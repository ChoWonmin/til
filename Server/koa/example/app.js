const Koa = require('koa');
const cors = require('@koa/cors');
const serve = require('koa-static');
const send = require('koa-send');

const app = new Koa();

app.use(serve('dist')); // build path
app.use(cors());
app.use(async (ctx) => {
  // ctx.body = {
  //   status: 'success',
  //   data: 'hello world'
  // };
  await send(ctx, './dist/index.html');
});

app.listen(3000);