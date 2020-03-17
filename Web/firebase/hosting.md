# Hosting

1. Firebase CLI 설치

```bash
npm install -g firebase-tools
```

2. Firebase Login & Init

```bash
firebase login
firebase init
```

3. 프로젝트 디렉토리 설정

4. 사이트 배포

```bash
firebase deploy
```

5. Firebase 웹 앱에 연결

## Performance Monitoring

https://firebase.google.com/docs/perf-mon/get-started-web?authuser=0

```js
import "firebase/performance";

firebase.initializeApp(config);
const perf = firebase.performance();
```

```shell
npm install --save-dev first-input-delay
```

```js
const trace = perf.trace("customTraceName");
trace.start();

// code that you want to trace

trace.stop();
```

---

## Multiple Site

https://firebase.google.com/docs/hosting/multisites?authuser=0

```
firebase target:apply hosting target-name resource-name
firebase deploy --only hosting:target-name
```

```json
{
  "hosting": [ {
      "target": "blog",  // "blog" is the applied target name for the Hosting site "myapp-blog"
      "public": "blog/dist",  // contents of this folder are deployed to the site "myapp-blog"

      // ...
    },
    {
      "target": "app",  // "app" is the applied target name for the Hosting site "myapp-app"
      "public": "app/dist",  // contents of this folder are deployed to the site "myapp-app"

      // ...

      "rewrites": [...]  // You can define specific Hosting configurations for each site
    }
  ]
}
```
