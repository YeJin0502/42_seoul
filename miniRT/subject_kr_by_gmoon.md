# miniRT

### My first RayTracer with miniLibX

이 프로젝트는 레이트레이싱을 소개한다. 일단 완성되면 당신은 간단한 컴퓨터-생성-이미지를 만들 수 있을 것이고, 다시는 수학 공식을 구현하는 것을 두려워하지 않을 것이다.

## Chapter 1. 서론

3차원 컴퓨터-생성-이미지를 렌더링할 때 두 가지 접근 방법이 있다. "Rasterization"는 효율성 때문에 주로 그래픽 엔진에서 사용됐고, "Ray Tracing"이 있다.<br>"Ray Tracing" 방법은 1968년에 처음으로 개발되어 지금까지 개선되었다. 이 방법은 오늘날까지도 "Rasterization" 방법보다 계산 비용이 비싸다. 이 때문에 "Ray Tracing"은 실시간 사용케이스에서는 잘 적용되지 않지만, 훨씬 더 높은 수준의 시각적 리얼리즘을 만들어준다.<br>이러한 고품질의 그래픽을 제작하기 위해선, 우선 당신은 기초를 마스터해야 한다. miniRT는 당신의 첫 ray tracer로 C에서 코딩되었으며, normed and humble but functionnal하다.<br>miniRT의 주 목적은 당신이 수학자가 되지 않고도 어떠한 수학이나 물리학 공식도 실행할 수 있다는 것을 증명하는 것이다. 우리는 아주 기본적인 ray tracing 기능만 구현할 것이니 침착하고 당황하지 마라! 이 프로젝트가 끝나면 당신은 학교에서 보내는 시간을 정당화하기 위해 멋진 사진을 보여줄 수 있을 것이다...

## Chapter 2. 일반 지침

- norm 규정을 지켜라. bonus 함수 또한 마찬가지.
- 함수가 정의되지 않은 행동을 하거나 예기치 않게 중단(segmentation fault, bus error, double free, etc)되어서는 안된다.
- 힙의 메모리는 꼭 적절히 free되어야 한다. leak은 허용되지 않는다.
- makefile을 요구할 경우, makefile은 -Wall -Wextra -Werror 플래그로 쓰여야 하며 $(NAME), all, clean, fclean, re 규칙을 포함해야 한다.
- bonus 함수를 추가한 경우, makefile에 bonus 룰을 추가해야 한다. 여기엔 메인 파트에서 금지되었었던 다양한 헤더와 라이브러리가 추가될 것이다. bonus 파일들은 _bonus.{c/h}로 만들어져야 한다. 메인 파트와 bonus 파트는 분리되어 평가될 것이다.
- libft 사용이 허락된 경우, source들과 makefile을 libft 폴더 안에 복사해라.
- 평가는 하지 않겠지만 테스트 프로그램을 만들 것을 권장한다.
- git 저장소의 작업물만 평가된다.

## Chapter 3. Mandatory part - miniRT

| Program name     | miniRT                                                       |
| ---------------- | ------------------------------------------------------------ |
| Turn in files    | All your files                                               |
| Makefile         | all, clean, fclean, re, bonus                                |
| Arguments        | a scene in format *.rt                                       |
| External functs. | open, close, read, write, malloc, free, perror, strerror, exit.<br>All functions of the math library (-lm man man 3 math).<br>All functions of the MinilibX. |
| Libft authorized | Yes                                                          |
| Description      | The goal of your program is to generate images using the Raytracing protocol. Those computer generated images will each represent a scene, as seen from a specific angle and position, defined by simple geometric objects, and each with its own lighting system. |

제약조건은 다음과 같다:

* 당신은 반드시 miniLibX를 사용해야 한다. 운영체제 또는 해당 소스에서 사용할 수 있는 버전이다. 만약 소스로 작업하기로 선택했으면, 일반 지침에 작성된 것과 동일한 규칙을 당신의 libft에 적용해야 한다.
* 창 관리가 원활하게 유지되어야 한다: 다른 창으로 변경, 최소화, 기타 등등.
* 최소한 다섯 개의 단순 기하학 물체가 필요하다: 평면, 구, 원통, 정사각형, 삼각형.
* 해당되는 경우, 가능한 모든 교차점과 물체 내부를 올바르게 처리해야 한다.
* 프로그램은 물체의 고유 속성 크기를 조정할 수 있어야 한다: 구의 지름, 사각형의 변 길이, 원통의 너비와 높이.
* 프로그램은 물체, 조명, 카메라에 변환 및 회전변환을 할 수 있어야 한다. (회전할 수 없는 구, 삼각형, 조명 제외)
* 조명 관리: spot brightness, hard shadows, 실내 조명(객체들이 결코 암흑에 있진 않다). colored and multi-spot lights를 적절히 처리해야 한다.
* 프로그램은 두번째 인수가 "--save" 인 경우, 렌더링된 이미지를 bmp 형식으로 저장해야 한다.
* 두번째 인수가 없는 경우, 프로그램은 이미지를 창에 표시하고 다음 규칙을 준수한다.
  * ESC를 누르면, 창을 닫고 프로그램을 완전 종료한다.
  * 프레임의 x 버튼을 누르면, 창을 닫고 프로그램을 완전히 종료한다.
  * 지정된 사이즈가 디스플레이 해상도보다 클 경우, 창 크기는 현재 디스플레이 해상도에 따라 조정된다.
  * 카메라가 두 개 이상이면, 지정한 키보드 키를 눌러 전환할 수 있어야 한다.
  * minilibX의 이미지 사용을 강력히 추천한다.
* 프로그램은 확장자가 .rt 인 파일을 첫번째 인수로 사용해야 한다. (Your program must take as a first argument a scene description file with the .rt extension.)

작성중...