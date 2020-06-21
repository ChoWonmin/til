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

파일

- nginx.conf
- sites-enabled
- fastcgi_params, scgi_params, uwsgi_params : 웹 서버와 어플리케이션 서버 사이에서 인터페이스 역할

sites-enabled 설정

1. include 확인

```nginx
# nginix.conf
include /etc/nginx/sites-enabled/*;
```

2. server > location

```nginx
server {
  listen 80;

  location / {
    proxy_pass http://127.0.0.1:3000/proxy_1;

    proxy_pass /test http://127.0.0.1:3000/proxy_2;
  }

  ...
```

## Reference

https://twpower.github.io/39-install-nginx-on-ubuntu-by-using-apt-get-and-brief-explanation

https://cheese10yun.github.io/Node-AWS-Nginx/

https://www.youtube.com/watch?v=SlBe9c54GzA

https://medium.com/sjk5766/nginx-reverse-proxy-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0-e11e18fcf843
