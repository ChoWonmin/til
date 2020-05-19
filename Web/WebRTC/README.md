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

### 3. NAT

Network Address Translation (NAT) is used to give your device a public IP address.
Some routers will have restrictions on who can connect to devices on the network. This can mean that even though we have the public IP address found by the STUN server, not anyone can create a connection. In this situation we need to turn to TURN.

4. TURN

Some routers using NAT employ a restriction called ‘Symmetric NAT’. This means the router will only accept connections from peers you’ve previously connected to.

Traversal Using Relays around NAT (TURN) is meant to bypass the Symmetric NAT restriction by opening a connection with a TURN server and relaying all information through that server. You would create a connection with a TURN server and tell all peers to send packets to the server which will then be forwarded to you. This obviously comes with some overhead so it is only used if there are no other alternatives.

---

## Reference

- https://developer.mozilla.org/ko/docs/Web/API/WebRTC_API
- https://github.com/webrtcHacks/adapter
- https://www.slideshare.net/ksdc2019/web-rtc-trouble-shooting
- https://github.com/react-native-webrtc/react-native-webrtc
