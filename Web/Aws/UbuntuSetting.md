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
curl https://raw.githubusercontent.com/creationix/nvm/master/install.sh | bash 
```

3. NVM path 설정

```
source ~/.bashrc
```

4. install node

```
nvm install --lts
nvm install 12
nvm use 12
```

## MongoDB

https://docs.mongodb.com/manual/tutorial/install-mongodb-on-ubuntu/

1. test GPG key

```
wget -qO - https://www.mongodb.org/static/pgp/server-4.2.asc | sudo apt-key add -
```

2. Create a list file for MongoDB

```
echo "deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu bionic/mongodb-org/4.2 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-4.2.list
```

3. Reload local package database.

```
sudo apt-get update
```

4. Install the MongoDB packages

```bash
# install latest stable version
sudo apt-get install -y mongodb-org

# apt-get이 업그레이드되면서 mongodb에 장애 주지않도록 설정
echo "mongodb-org hold" | sudo dpkg --set-selections
echo "mongodb-org-server hold" | sudo dpkg --set-selections
echo "mongodb-org-shell hold" | sudo dpkg --set-selections
echo "mongodb-org-mongos hold" | sudo dpkg --set-selections
echo "mongodb-org-tools hold" | sudo dpkg --set-selections
```
