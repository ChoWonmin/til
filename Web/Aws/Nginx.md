# Nginx

## Install

```
sudo apt-get install nginx
```

## Basic

```bash
sudo service nginx start
sudo service nginx restart
sudo service nginx stop
sudo service nginx status
# 설정
sudo service nginx reload
```

## 설정 파일

경로

- apt-get: /etc/nginx
- compile: /usr/local/nginx/conf, /usr/local/etc/nginx

```
sudo find / -name nginx.conf
```

## Reference

https://twpower.github.io/39-install-nginx-on-ubuntu-by-using-apt-get-and-brief-explanation
https://cheese10yun.github.io/Node-AWS-Nginx/
