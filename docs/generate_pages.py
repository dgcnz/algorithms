from utils.parser import get_parsed_folder
from datetime import datetime
from pathlib2 import Path
from string import Template
import subprocess
import pprint

pp = pprint.PrettyPrinter(indent=4)

TO_PARSE = ['../codeforces', '../atcoder', '../cses', '../uva']
# TO_PARSE = ['../codeforces/102694E-filthy-rich-trees.cpp']

TEMPLATE = Template("""---
layout: post
mathjax: true
title: $title
problem_url: $problem_url
tags: $tags
memory_complexity: $memory_complexity
time_complexity: $time_complexity
---

$idea


{% if page.time_complexity != "None" %}
- Time complexity: $${{ page.time_complexity }}$$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: $${{ page.memory_complexity }}$$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
$source_code
{% endraw %}
```""")

ATTR_FIELDS = [
    'title', 'url', 'tags', 'time_complexity', 'memory_complexity', 'idea'
]


def main():
    files_dict = get_parsed_folder(TO_PARSE)
    for file_dict in files_dict:
        attributes = file_dict['attributes']
        source_file = Path(file_dict['source_file'])
        creation_date = datetime.fromtimestamp(source_file.stat().st_ctime)

        new_filename = f'{creation_date.strftime("%Y-%m-%d")}-{source_file.stem}.md'
        with open(f'_posts/{new_filename}', 'w') as f:
            text = TEMPLATE
            payload = {
                attr: attributes.get(attr, None)
                for attr in ATTR_FIELDS
            }
            if payload['title'] is None:
                alt_title = (' '.join(source_file.stem.split('-'))).title()
                payload['title'] = alt_title

            if payload['url'] is not None:
                payload['problem_url'] = payload['url']
                del payload['url']

            print(source_file)
            output = subprocess.run(
                ['g++', '-E', '-P', '-nostdinc', source_file],
                capture_output=True)

            payload['source_code'] = output.stdout.decode('utf-8')

            s = text.substitute(**payload)
            f.write(s)


if __name__ == '__main__':
    main()
