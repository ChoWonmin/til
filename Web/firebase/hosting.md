# Hosting

1. Firebase CLI 설치

``` bash
npm install -g firebase-tools
```
2. Firebase Login & Init
``` bash
firebase login
firebase init
```

3. 프로젝트 디렉토리 설정

4. 사이트 배포
``` bash
firebase deploy
```

5. Firebase 웹 앱에 연결

## Performance Monitoring

https://firebase.google.com/docs/perf-mon/get-started-web?authuser=0

```js
import 'firebase/performance';

firebase.initializeApp(config);
const perf = firebase.performance();
```

```shell
npm install --save-dev first-input-delay
```

```js
const trace = perf.trace('customTraceName');
trace.start();

// code that you want to trace

trace.stop();
```
