# :pineapple: PINE APPLE SHELL
***minishell by [gmoon](https://github.com/moon9ua) and [sanam](https://github.com/simian114).***<br>
***@ 42 Seoul***

![GIF](GIF.gif)

공부한 기록은 [노션](https://www.notion.so/minishell-d7163467fb3b441f98b972b18e1447b8)으로.

## 참고자료

* https://brennan.io/2015/01/16/write-a-shell-in-c/ <br>
당시에는 참고하지 않았지만 읽어볼만한 글.

\# redirection
* http://www.sarathlakshman.com/2012/09/24/implementation-overview-of-redirection-and-pipe-operators-in-shell

\# pipe
* https://gist.github.com/iomonad/a66f6e9cfb935dc12c0244c1e48db5c8
* https://github.com/LambdaSchool/CS-Wiki/wiki/How-Unix-Pipes-are-Implemented

\# escape 문자
* https://unix.stackexchange.com/questions/390148/escaping-in-double-quotes-in-bash-scripts

## 개선할 점

귀찮아서 수정은 못했으나, 다음과 같은 문제점들이 있었다.

* minishell에서 환경변수를 수정 후 다른 프로그램을 실행시키면, 수정된 환경변수가 아닌 원본 환경변수가 전달되는 문제점이 있다. 이는 환경변수를 다루는 함수를 만들 때, 복사본(연결리스트로 구현함)을 수정하게 만들었기 때문이다.

(이 글을 보고있으시다면 처음부터 고려해서 만들시길 바랍니다. T_T)
