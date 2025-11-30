# [Gold II] No Nine - 23956 

[문제 링크](https://www.acmicpc.net/problem/23956) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 자릿수를 이용한 다이나믹 프로그래밍, 수학, 정수론

### 제출 일자

2025년 12월 1일 00:33:02

### 문제 설명

<p>No Nine is a counting game that you can try when you are bored. In this game, you are only allowed to say numbers that are <i>legal</i>. A number is legal if and only if <u>all</u> of the following are true:</p>

<ul>
	<li>it is a natural number (i.e. in the set {1, 2, 3...})</li>
	<li>it does not contain the digit 9 anywhere in its base 10 representation</li>
	<li>it is not divisible by 9</li>
</ul>

<p>For example, the numbers 16 and 17 are legal. The numbers 18, 19, 17.2, and -17 are not legal.</p>

<p>On the first turn of the game, you choose and say a legal number <b>F</b>. On each subsequent turn, you say the next legal number. For example, if you played a game with <b>F</b> = 16, you would say 16, 17, 20, 21, and so on.</p>

<p>Alice is very good at this game and never makes mistakes. She remembers that she played a game in which the first number was <b>F</b> and the last number was <b>L</b> (when she got tired of the game and stopped), and she wonders how many turns were in the game in total (that is, how many numbers she said).</p>

### 입력 

 <p>The input starts with one line containing one integer <b>T</b>; <b>T</b> test cases follow. Each test case consists of a single line containing two integers <b>F</b> and <b>L</b>: the first and last numbers from the game, as described above.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1), and <code>y</code> is the number of the turns played in the game.</p>

