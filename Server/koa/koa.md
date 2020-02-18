# koa

### install
```
npm i koa --save
npm i @koa/cors --save
npm i koa-send --save
npm i koa-static --save
```

### koa app.js
``` js
const Koa = require('koa');
const cors = require('@koa/cors');
const serve = require('koa-static');
const send = require('koa-send');

const app = new Koa();

app.use(serve('dist')); // build path
app.use(cors());
app.use(async (ctx) => {
  await send(ctx, './dist/index.html');
});

app.listen(3000);
```

### package.json
``` js
"scripts": {
  // vue-cli
  "build": "vue-cli-service build",
  "publish": "node app.js"
}
```
### running
```
npm run build
npm run publish
```


https://github.com/koajs/koa
