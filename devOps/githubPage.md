# git pages

### default url

https://chowonmin.github.io/

### default url

master/docs

### GitHub의 DNS Provider IP

- _192.30.252.153_
- _192.30.252.154_

### CNAME 설정

### Vue-cli-service

### vue.config.js

```js
module.exports = {
  publicPath: process.env.NODE_ENV === ‘production’
    ? ‘/my-project/‘
    : ‘/‘
}
```

### deploy.sh

```sh
#!/usr/bin/env sh

# abort on errors
set -e

# build
npm run build

# navigate into the build output directory
cd dist

# if you are deploying to a custom domain
# echo 'www.example.com' > CNAME

git init
git add -A
git commit -m 'deploy'

# if you are deploying to https://<USERNAME>.github.io
# git push -f git@github.com:<USERNAME>/<USERNAME>.github.io.git master

# if you are deploying to https://<USERNAME>.github.io/<REPO>
# git push -f git@github.com:<USERNAME>/<REPO>.git master:gh-pages

cd -
```
