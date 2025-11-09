# P02D13


Foydali video materiallarni Platformadagi “Projects (Media)” bo‘limida topishingiz mumkin. 

![dayp02](misc/rus/images/dayp02.png)

## Contents

1. [Chapter I](#chapter-i) \
 1.1. [Level 2. Hall.](#level-2-hall)
2. [Chapter II](#chapter-ii)\
 2.1. [List 1.](#list-1)
 

# Chapter I

## Level 2. Hall.

***LOADING Level 2… \
LOADING Hall…***

Yaqinda sen shunga o’xshash ayvonda bo’lganding. Yoki bunga ancha vaqt bo’ldimi? Buni aytish qiyin. Hamma narsa aralashib ketdi. Ayvonning uzoq burchagida yana ovozlar eshitilyapti. Demak, sen yana bu yerda yolg'iz emassan. 
Bugun ayvon yorqin yorug’likka to'lgan va mukammal tozalik mavjud. Turli xillik – bu yaxshi.

To’satdan kolonkalardan aniq, kristal toza eshitiladigan yangradi:

>Salom. \
>O’zimni tanishtirishga ijozat eting. Men mulohaza bilan tahlil qiluvchi modul M-53. Aniqlanmagan sabablarga ko’ra men bu o’ta zerikarli ayvonga kelib qoldim. Albatta, ma’suliyat katta va hokazolar lekin bu yerda mulohaza qiladigan narsa yo’q. Meni yaratayotgan payt, boshqa materiallar ichida men bir qiziqarli maqola bo’yicha ta’lim oldim. Uning qog’oz nusxasi A1B18 qutisida turibti. Ha, shu yerda. Sizga kichik iltimosim bor- maqoladagi The Game of Life ni ishlab chiqaring, umid qilamanki o’sha meni ozgina ko’nglimni ochadi. Boshingiz omon bo’lsin. Grafik ishlovi eng oddiy bo’lishi mumkin – men xolis tomoshabinman. Terminaldagi psevdografika ham mos keladi. Agar holatni matritsa yordamida ishga tushirish – va mulohaza qilish mumkin bo’lganida edi. Klassik to’plamdan kamida 5 ta boshlang’ich initsializatsiyalarni tayyorlash ortiqcha bo’lmasdi (ko’p yashovchi turg’un figuralar, davriy figuralar, harakatlanadigan figuralar, miltiq, paravozlar, yutuvchilar, ars ettiruvchilar, ko’paytiruvchilar va hokazo.) \
>Natijalarni intizorlik bilan kutaman! \
>Raxmat.

***== Quest qabul qilindi. SIi dasturlash tilida «The Game of Life» aks ettirilgan src/game_of_life.c dasturini ishlab chiqing. Grafiklarni ko'rsatish uchun faqat belgilar (ASCII) grafiklaridan foydalanish (terminalga chiqarish bilan). Shuningdek, "o'yin" tezligini va uni tugatish qobiliyatini sozlash variantlarini yarating. O'yinchi harakatlarini qayta ishlash va belgilar grafikasini ko'rsatishni soddalashtirish uchun siz "ncurses" kutubxonasidan foydalanishingiz mumkin. ==***

* ***Grafika*** 

Maydon – 80 ga 25 katakli to’g’ri to’rtburchak.

Maydon "o'z-o'ziga yopilgan" deb taxmin qilinadi, masalan, pastgi o’ng kvadratning qo’shnisi bo’lib, pastgi qo’shnisi esa-yuqori o’ng tomon kvadrat hisoblanadi. 

Stdin orqali "o'yin" holatini dastlabki ishga tushirishni oldindan nazarga olish. 

Kkirishni qayta yo’naltirish orqali tez ishga tushurish va initsializatsiya uchun boshlang’ich holat bilanli kamida 5 ta fayl tayyorlash.

## Muhim eslatmalar

* O’yin SIi tilida, strukturaviy rejimda ishlab chiqilishi va terminaldan ishlashi lozim.
  
* Sening boshlang’ich koding statistic tahlilchi ```cppcheck``` da shuningdek ```clang-format``` uslubi linterida tekshiriladi.

* Bu testlarni kompyuterda ishga tushirish bo’yicha yo’riqnoma `materials` papkasida joylashgan.

* Katta funksiyalardan foydalanma, 40-50 ta qator bilan kifoyalan.

* O’z dasturingni xotira sizib chiqishiga tekshir!

> O’yinni ishlab chiqishda to’la ravishda E.Deykstraning struktaraviy dasturlash prinsiplaridan foydalan.

***LOADING...***


# Chapter II

## List 1.

>The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine.
>
>The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:
>
>Any live cell with fewer than two live neighbours dies, as if by underpopulation.
>Any live cell with two or three live neighbours lives on to the next generation.
>Any live cell with more than three live neighbours dies, as if by overpopulation.
>Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
>These rules, which compare the behavior of the automaton to real life, can be condensed into the following:
>
>Any live cell with two or three live neighbours survives.
>Any dead cell with three live neighbours becomes a live cell.
>All other live cells die in the next generation. Similarly, all other dead cells stay dead.
>The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick. Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.
>
>In late 1940, John von Neumann defined life as a creation (as a being or organism) which can reproduce itself and simulate a Turing machine. Von Neumann was thinking about an engineering solution which would use electromagnetic components floating randomly in liquid or gas. This turned out not to be realistic with the technology available at the time. Stanislaw Ulam invented cellular automata, which were intended to simulate von Neumann's theoretical electromagnetic constructions. Ulam discussed using computers to simulate his cellular automata in a two-dimensional lattice in several papers. In parallel, von Neumann attempted to construct Ulam's cellular automaton. Although successful, he was busy with other projects and left some details unfinished. His construction was complicated because it tried to simulate his own engineering design. Over time, simpler life constructions were provided by other researchers, and published in papers and books.
>
>Motivated by questions in mathematical logic and in part by work on simulation games by Ulam, among others, John Conway began doing experiments in 1968 with a variety of different two-dimensional cellular automaton rules. Conway's initial goal was to define an interesting and unpredictable cell automaton. For example, he wanted some configurations to last for a long time before dying and other configurations to go on forever without allowing cycles. It was a significant challenge and an open problem for years before experts on cellular automata managed to prove that, indeed, the Game of Life admitted of a configuration which was alive in the sense of satisfying Von Neumann's two general requirements. While the definitions before the Game of Life were proof-oriented, Conway's construction aimed at simplicity without a priori providing proof the automaton was alive.
>
>Conway chose his rules carefully, after considerable experimentation, to meet these criteria:
>
>There should be no explosive growth.
>There should exist small initial patterns with chaotic, unpredictable outcomes.
>There should be potential for von Neumann universal constructors.
>The rules should be as simple as possible, whilst adhering to the above constraints.
>The game made its first public appearance in the October 1970 issue of Scientific American, in Martin Gardner's "Mathematical Games" column. Theoretically, the Game of Life has the power of a universal Turing machine: anything that can be computed algorithmically can be computed within the Game of Life. Gardner wrote, "Because of Life's analogies with the rise, fall and alterations of a society of living organisms, it belongs to a growing class of what are called 'simulation games' (games that resemble real life processes)."
>
>Since its publication, the Game of Life has attracted much interest because of the surprising ways in which the patterns can evolve. It provides an example of emergence and self-organization. Scholars in various fields, such as computer science, physics, biology, biochemistry, economics, mathematics, philosophy, and generative sciences, have made use of the way that complex patterns can emerge from the implementation of the game's simple rules. The game can also serve as a didactic analogy, used to convey the somewhat counter-intuitive notion that design and organization can spontaneously emerge in the absence of a designer. For example, cognitive scientist Daniel Dennett has used the analogy of the Game of Life "universe" extensively to illustrate the possible evolution of complex philosophical constructs, such as consciousness and free will, from the relatively simple set of deterministic physical laws which might govern our universe.
>
>The popularity of the Game of Life was helped by its coming into being at the same time as increasingly inexpensive computer access. The game could be run for hours on these machines, which would otherwise have remained unused at night. In this respect, it foreshadowed the later popularity of computer-generated fractals. For many, the Game of Life was simply a programming challenge: a fun way to use otherwise wasted CPU cycles. For some, however, the Game of Life had more philosophical connotations. It developed a cult following through the 1970s and beyond; current developments have gone so far as to create theoretic emulations of computer systems within the confines of a Game of Life board.
>
![glider_emblem](materials/glider_emblem.gif)

***LOADING...***

