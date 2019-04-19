# Appliacion Layer

> 서비스가 완성되기 위해서 어떻게 요청/응답을 할지 고민, 실제로 데이터가 전달되는지는 신경쓰지 않는다.

## Conceptual, implementaion aspect of network appliacion protocols

- client-server paradigm
- peer-to-peer paradigm
- transport-layer service models

## Appliacion lavel protocols

- HTTP
- FTP
- SMTP / POP3 / IMAP
- DNS

### Socket API

> creationg network applications. transport 부터는 os가 담당. application에서 다루기 위해서는 socket api를 이용한다.

### network apps

- Remote login
- e-mail
- web
- text messaging
- P2P file sharing
- multi user network game
- streaming stored video (youtube, netflix)
- social networking
- searching
- etc ...

## Client-Server

### Server

> - always-on host, 항상 켜있어야한다
> - parnabebt IP address
> - data center

## Addressing process

- IP address
- port number

## Appliacion lavel protocol defines

- types of messages exchanged : request, responese로 이루어진다.
- message syntax : 메시지 형식, 어떤 것을 명시해야하는지 어떤 형태로 적어야하는지
- message semantics : meaning of information in fields. 각각의 필드에 값을 어떻게 해석할 것인가
- rule

## Appliacion Characteristics

- data integrity : video, voice는 loss가 존재해도 된다.
- timing
- throughput : 최소한의 실제 전달량이 보장되어야한다.
- security : encryption, deta integrity(위조되지 않는 것)

## TCP

- Reliable transport : 수신자는 무조건 데이터를 받아야함
- flow control : 단위 시간당 수신자가 수용할 수 있는만큼 보내겠디.
- congestiong control : 네트워크에서 수용할 수 있는만큼 보내겠다.
- connection-oriented : 연결이되고나서 보내겠다.

보장하지 않는 것 : timing, 최소 단위 전송량, security

## UDP

- unreliable

보장하지 않는 것 : reliabliity, flow control, congestion control, timing, throughput guarantee, security
