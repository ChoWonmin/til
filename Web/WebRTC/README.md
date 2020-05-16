# WebRTC

### WebRTC(Web Real-Time Communications)

- web browser, android, ios 지원
- 플러그인 필요 없이 사용 가능

---

## Protocol

### 1. ICE

Interactive Connectivity Establishment (ICE) is a framework to allow your web browser to connect with peers. ICE uses STUN and/or TURN servers to accomplish this, as described below.

### 2. STUN

Session Traversal Utilities for NAT (STUN) (acronym within an acronym) is a protocol to discover your public address and determine any restrictions in your router that would prevent a direct connection with a peer.

The client will send a request to a STUN server on the Internet who will reply with the client’s public address and the client is accessible behind the router’s NAT.

---

## Reference

- https://developer.mozilla.org/ko/docs/Web/API/WebRTC_API
- https://github.com/webrtcHacks/adapter
- https://www.slideshare.net/ksdc2019/web-rtc-trouble-shooting
- https://github.com/react-native-webrtc/react-native-webrtc
