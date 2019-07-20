# Hosting

1. Firebase CLI 설치
2. 프로젝트 디렉토리 설정
3. 사이트 배포
4. Firebase 웹 앱에 연결

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
