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

## subprocess detail

### basic

```python
import subprocess

p1 = subprocess.run(["ls", "-l"])

print(p1) # CompletedProcess(args=['ls', '-l'], returncode=0)
print(p1.args) # ['ls', '-l']
print(p1.stdout) # None

```

### stdout

```python
import subprocess

p1 = subprocess.run(["ls", "-l"], capture_output=Ture)

print(p1.stdout.decode())
# drwxr-xr-x   7 wonmin  staff  224 Apr 30 22:10 example01
# drwxr-xr-x   5 wonmin  staff  160 Jun 25  2019 example02


p1 = subprocess.run(["ls", "-l"], capture_output=Ture, text=True)
p1 = subprocess.run(["ls", "-l"], stdout=subprocess.PIPE, text=True)

print(p1.stdout)
print(p1.stdout)
# drwxr-xr-x   7 wonmin  staff  224 Apr 30 22:10 example01
# drwxr-xr-x   5 wonmin  staff  160 Jun 25  2019 example02
```

### file

```python
import subprocess

with open('output.txt', 'w') as f:
  p1 = subprocess.run(["ls", "-l"], stdout=f, text=True)
```

### error

```python
import subprocess

p1 = subprocess.run(["ls", "-l", "not_exist_file"], capture_output=Ture, text=True)

print(p1.returnCode) # 1
print(p1.stderr) # ls: not_exist_file: No such file or ditectory

p1 = subprocess.run(["ls", "-l", "not_exist_file"], capture_output=Ture, text=True, check=True)
# python throws error
```

### pipeline

```python
import subprocess

p1 = subprocess.run(["cat", "text.txt"], capture_output=Ture, text=True)
p2 = subprocess.run(["grep", "-n", "search_word"], capture_output=Ture, text=True, input=p1.stdout)

## p1, p2 실행과 동일
p3 = subprocess.run("cat text.txt | grep -n search_word", capture_output=Ture, text=True, shell=True)
```
