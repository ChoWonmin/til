# Ubuntu Setting

## 키페어 적용

1. .pem 다운로드
2. .ssh 하위 폴더로 .pem 이동
   - https://aws.amazon.com/ko/premiumsupport/knowledge-center/ec2-linux-fix-permission-denied-errors/
   - https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/ec2-instance-connect-set-up.html
3. chmod 400 ###.pem

## install nvm

1. 빌드 환경 설치

```
sudo apt-get install build-essential libssl-dev
```

2. download nvm

```
curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.11/install.sh | bash
```

3. NVM path 설정

```
source ~/.bashrc
```

4. install node

```
nvm install 12
nvm use 12
```
