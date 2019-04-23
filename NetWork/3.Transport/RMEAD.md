# Transport Layer

> application에서 만든 메세지를 확실하게 전달할 수 있도록한다. 단위시간당 전소량과 딜레이를 보장할 수 없다.

## TCP : reliable, in-order delivery

- congestion control : congestion은 네트워크 레이어에서 발생하지만 end system에서 데이터를 너무 많이 보내기 때문이다. 네트워크 상태에 맞추어서 application layer를 통제한다.
- flow control : 수신자가 받을 수 있는 만큼만 데이터를 보낸다.
- connection setup

## UDP : unreliable, unordered delivery

## Multiplexing and Demultiplexing

transport layer부터는 os가 담당한다.
sender는 app에서 os로 multiplexing, receiver는 app에서 os로 demultiplexing이 포트번호를 통해 가능하다.

## Reliable data transfer

transport에서는 네트워크 layer가 놓지는 데이터를 application layer에게 보장해야한다.
