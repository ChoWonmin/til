# Python subprocess module

- 파이썬에서 system command를 사용할 수 있는 모듈
- standard library

## Usage

```python
import subprocess

# 3.5 or later version
subprocess.run(["ls", "-l"])
# before 3.5 version
subprocess.call(["ls", "-l"])
```

---

## subprocess vs os.system

```python
import os

os.system("ls -l")
```

- os.system()으로도 system command를 사용 가능
