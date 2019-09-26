# log 적재하는 명령어

프로그램의 log를 적재하는 명령어

## example

print_text.sh
``` bash
ls -al test.txt
```
>> print_text.sh > your_dir/print_text.log 2>your_dir/print_text.log 2
>> print_text.sh > your_dir/print_text.log 2>&1 # 축약
print_text.sh의 출력 결과 및 에러를 print_text.log에 적재


### 파일 디스크립터

|번호||
|-|-|
|0|표준 입력|
|1|표준 출력|
|2|표준 에러|