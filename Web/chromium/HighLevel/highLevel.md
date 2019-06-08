# High Level Architecture

> describes Chromium's high-level architecture

## Architectural overview

Chromium은 rendering engine의 안정성을 위해서 tab 별로 proccess를 나누었다. rendering engine process이 다른 시스템에 접근하는 것을 제한했다.

memory protection and access control brought to operating systems의 이점을 가진다.

1. browser process

- main process that runs the UI and manages tab and plugin processes

2. render processes , renderers

- the tab-specific processes
- [Blink open-source layout engine](https://www.chromium.org/blink) for interpreting and laying out HTML

![architecture](./images/arch.png)

### Managing render processes

**Browser** 와 **Renderer**는 [Chromium's IPC system](https://www.chromium.org/developers/design-documents/inter-process-communication)로 통신한다.

1. Global RenderProcess (**Browser**)

- manages communication with the parent browser process and maintains global state

2. RenderProcessHost (**Renderer**)

- exist each render process
- manages browser state and communication for the renderer

### Managing views

[참고문서](https://www.chromium.org/developers/design-documents/multi-process-architecture)
