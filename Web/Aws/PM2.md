# PM2

## install

```
npm install pm2 -g
```

## run http-server

```
which http-server
pm2 start #### --name app_name -- -p 3000 -d false
```

## manage

```
pm2 stop id|name
pm2 delete id|name

pm2 kill
```
