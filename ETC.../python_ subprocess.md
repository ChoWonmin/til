# Python subprocess module

- 파이썬에서 system command를 사용할 수 있는 모듈
- standard library

## Usage

```python
import subprocess

# 3.5 or later version
subprocess.run(["ls", "-l"])
subprocess.run("ls -l", shell=True)
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
- python official document에서는 subprocess로 대체하기를 권장
- https://docs.python.org/3/library/os.html#os.system
