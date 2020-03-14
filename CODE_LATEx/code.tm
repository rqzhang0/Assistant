<TeXmacs|1.99.2>

<style|article>

<\body>
  <doc-data|<doc-title|CODES' NOTE>>

  FUCKING CODER

  <section|SHELL >

  <subsection|Basic Function>

  \;

  The Function of SHELL:

  Interpret the user's input and excute these commands.

  \;

  Shell do three things in its <with|font-series|bold|LifeTime:>

  <\itemize>
    <item>Initialize

    <item>Interpret

    <item>Terminate
  </itemize>

  \;

  \;

  The functions of shell can be divided into three parts:

  <\itemize>
    <item>Read Command

    <item>Understand Command

    <item>Excute Command
  </itemize>

  \;

  <with|font-series|bold|Read Command:>

  Generally, Shell read in a string and store it into an array.

  <with|font-series|bold|step1.> To read in Command, we need
  \ <with|font-series|bold|getchar()> function.

  \ \ \ \ \ \ \ \ \ \ \ <with|font-series|bold|getchar()> function read in
  one single char each time. So we need a loop to make it.\ 

  <with|font-series|bold|step2.> We need to decide when to finish reading.\ 

  \ \ \ \ \ \ \ \ \ \ \ Typically when we accept an
  <with|font-series|bold|Enter> or <with|font-series|bold|EOF>, we need to
  stop reading in.

  \ \ \ \ \ \ \ \ \ \ \ \ <with|font-series|bold|EOF:> end of file. value is
  <math|-1>.

  \;

  <with|font-series|bold|Understand Command:>

  It means that we need to extract information from strings. Typically, we
  need to know what program is required, what arguments it has. To simplify
  our program, we understand the input as\ 

  <with|font-series|bold|Programm+argumenmts.>

  It means that the first char should be the name of the program we want to
  call. The left chars are these required arguments.

  These commands and arguments should be divided by space,
  tab(<math|\<backslash\>t><with|font-series|bold|>),return(r),newline(n),vertical
  tab(v).

  Namely we have

  <with|font-series|bold|step1.> split string according to there characters.
  we use <with|font-series|bold|strtok> function to split string. And we also
  need a loop to iteratively split the string.\ 

  <with|font-series|bold|step2.> store there char into array.

  \;

  <with|font-series|bold|Excuted Commands:>

  \;

  <section|My First Own Project: <with|font-series|bold|Assistant>>

  \;

  <with|font-series|bold|The advantage of this CODE:>

  <\itemize>
    <item>If your code is correct, you don't have to check your code every
    time;

    <item>It would work for different work;

    <item>It would work for different operators, you don't have to wirte code
    explicitely for each operator. Namely, if you want you can easily
    generate the code that calculate 12 different kinds of \ operators.\ 
  </itemize>

  It's function would include\ 

  <\itemize>
    <item>code generation (c);

    <item>File management, including encryption, sorting, searching ... and
    writting assistant;

    <item>Reminder;

    <item>Help derivation;

    <item>Automatic web searching, sorting, saving, analyzing...
  </itemize>

  \;

  This project would be a highly personalize and it will be an assisant of
  myself.

  <subsection|Assistant for Contraction>

  \;

  <\eqnarray*>
    <tformat|<table|<row|<cell|C<around*|(|t|)>>|<cell|=>|<cell|\<Phi\><rsub|\<alpha\>
    \<beta\>><rsup|B a b><around*|(|t<rprime|'>|)>
    \<tau\><rsub|\<beta\>\<gamma\>><rsup|b c><around*|(|t<rprime|'>,t|)>
    \<Phi\><rsub|\<gamma\> \<kappa\>><rsup|A c d><around*|(|t|)>
    \<tau\><rsub|\<kappa\> \<alpha\>><rsup|d
    a><around*|(|t,t<rprime|'>|)>>>>>
  </eqnarray*>

  Conver this line (latex source code) to\ 

  <with|font-series|bold|Pseudo code:>

  for a,b,c,d

  for <math|\<alpha\>,\<beta\>,\<gamma\>,\<kappa\>>

  for(<math|t<rprime|'>>)

  \ <math|<tabular|<tformat|<table|<row|<cell|C<around*|(|t|)>>|<cell|=>|<cell|\<Phi\><rsub|\<alpha\>
  \<beta\>><rsup|B a b><around*|(|t<rprime|'>|)>
  \<ast\>\<tau\><rsub|\<beta\>\<gamma\>><rsup|b
  c><around*|(|t<rprime|'>,t|)>\<ast\> \<Phi\><rsub|\<gamma\>
  \<kappa\>><rsup|A c d><around*|(|t|)>\<ast\> \<tau\><rsub|\<kappa\>
  \<alpha\>><rsup|d a><around*|(|t,t<rprime|'>|)>>>>>>><math|> <math|>

  <math|\<Rightarrow\>>

  \ corr[0][t_src][t]+=vector_products[0][t_snk][c1][c2]*gamma[s1][s2]*peram[t_src][t][s2][s3][c2][c3]*conj(vector_products[0][t_src][c4][c3])*gamma[s3][s4]*peram_back[t_src][t][s4][s1][c4][c1];

  \;

  \;

  <with|font-series|bold|Convert function:>

  <\itemize>
    <item><with|font-series|bold|Step1.>split line according to *, and
    <math|=> ;

    <item><with|font-series|bold|Step2>.split token according to bracket ']'
    and '[';

    <item><with|font-series|bold|Step3.>split these string in
    <math|<around*|[|\<ldots\>|]>> according to
    <math|<rprime|'>,<rprime|'>>and interpret it as index ;

    <item><with|font-series|bold|Step4.>Determine repeated indexes;

    <item><with|font-series|bold|Step5.>Write a <with|font-series|bold|for>
    loop for each repeated index.
  </itemize>

  <with|font-series|bold|Qusetions:>

  <\itemize>
    <item><with|font-series|bold|Q1.>Firstly, How to determine which index is
    repeated;

    <item><with|font-series|bold|Q2.> How to combine these variables with
    corresponding indexes.

    <item><with|font-series|bold|Q3.> How to deal with these indexes that
    repreated but doesn't need loop over ?

    <item><with|font-series|bold|Q4.> How to deal with these operators\ 

    <item><with|font-series|bold|Q5.> The OpenQCD not only difficult in
    programming but also in theory of Lattice, if we want to totally
    understanding these things, It would be very time consumming. How to
    solve this ?
  </itemize>

  <with|font-series|bold|Solutions:>

  <\itemize>
    <item><with|font-series|bold|S1.> \ We should write a simple function to
    search repeated indexes;

    <item><with|font-series|bold|S2.> \ We should store variables and
    corresponding indexes as <math|var<around*|[|i|]><around*|[|j|]>>.
    <math|var<around*|[|i|]><around*|[|0|]>> stores the variable name,
    <math|var<around*|[|i|]><around*|[|1-n|]>> store the indexes of i-th
    variable.**Var can only denote one single variable. So we need
    Var[nv][nid][nname]. So that Var[0][0]<math|\<rightarrow\>> represents
    the variable name, Var[0][1]<math|\<rightarrow\>> represents the number
    of indexes,n, Var[0][2...n+2]<math|\<rightarrow\>>indexes;

    <item><with|font-series|bold|S3.> \ \ <math|\<Phi\>> has only one time
    index while <math|\<tau\>> has two time indexes. But we don't have to
    repeated with these time indexes, so we don't have to deal with it.
    <math|\<Phi\>> looks like <math|\<Phi\><around*|[|p,t,\<ldots\>|]>>,
    <math|\<tau\>> looks like <math|\<tau\><around*|[|t,t<rprime|'>,\<ldots\>|]>>
    So we just only need to left first two indexes unchanged.\ 

    <item><with|font-series|bold|S4.> \ For simplicity, we don't deal with
    bracket operaters seperately. Our input only include operators like
    <math|+,-,=,\<ast\>\<cdot\>> These operaters should be intepreted in a
    sequence. Firstly, the <math|<rprime|'>=<rprime|'>>. Secondly,
    <math|<rprime|'>+<rprime|'>> and <math|<rprime|'>-<rprime|'>>. Finally,
    the <math|<rprime|'>\<ast\><rprime|'>>. In this way, we can know what
    operator is intepreting. To not forget any operator, we should store
    operators with correspoinding variables. For example, <math|a= b+c>. We
    should interpret it as <math|a>, <math|=b>, <math|+c>. Genearlly, for a
    expression like <math|a=b\<ast\>f+c-g> \ \ 

    <\itemize>
      <item><with|font-series|bold|Step1.> Interpret it as
      <math|a>,<math|=b\<ast\>f>,<math|+c>,<math|-g>;

      <item><with|font-series|bold|Step2.> Interpret <math|=b\<ast\>f> as
      <math|=b>, <math|\<ast\>f>;

      <item><with|font-series|bold|Step3.> combine <math|a,=b,\<ast\>f,+c,-g>
      to be c code; <math|a=b*\<ast\>f+c-g>. We only need to just combine
      these operators.\ 

      <item><with|font-series|bold|Step4.> Usually, an variable would have
      several indexes so we need to interpret these indexes. For example,
      <math|a<around*|[|t,t<rprime|'>,\<alpha\>,\<beta\>,a,b|]>> should be
      interpret as <math|a<around*|[|t|]><around*|[|t<rprime|'>|]><around*|[|\<alpha\>|]><around*|[|\<beta\>|]><around*|[|a|]><around*|[|b|]>>.
      It should be split by <math|<left|[>\<nocomma\>> and
      <math|<rprime|'>,<rprime|'>>.
    </itemize>

    <item><with|font-series|bold|S5.> If we spend time to understand the
    background of these theory, we may don't have time to improve our
    programming skill. Note that our original purpose is just to practice our
    programming skill. On the other hand, understand these theory may help us
    understanding OpenQCD. But we still facing some problems. Firstly, we may
    can't find everthing that we want. Secondly, It's \ quit boring to read
    these documents. Thirdly, if we have all the documents we want, we still
    need to read the source code. On the other hand, you should note that,
    the source code of <with|font-shape|italic|OpenQCD> is easy to read.
    <with|font-series|bold|So, we should read the source code and convert
    these codes into formula and logic.> In this way, even though we can't
    totally understand the source code, but we can also understand most of
    it. In the futuer, we can learn these backgrounds and then we can totally
    understand the OpenQCD.
  </itemize>

  \;

  <with|font-series|bold|Summary of Convert function:>

  <\itemize>
    <item><with|font-series|bold|Step1.> split according to
    <math|<rprime|'>=<rprime|'>>;

    <item><with|font-series|bold|Step2.> split according to
    <math|<rprime|'>+<rprime|'>>;

    <item><with|font-series|bold|Step3.> split according to
    <math|<rprime|'>-<rprime|'>>;

    <item><with|font-series|bold|Step4.> split according to
    <math|<rprime|'>\<ast\><rprime|'>>;

    <item><with|font-series|bold|Step5.> For each token, split according to
    <math|<rprime|'><left|[><rprime|'>> and
    <math|<rprime|'><right|]><rprime|'>>;

    <item><with|font-series|bold|Step6.> Store these chars in
    <math|<rprime|'><left|[><rprime|'>> and
    <math|<rprime|'><right|]><rprime|'>> as
    indexes,<math|var<around*|[|vname|]><around*|[|indexes|]>>;

    <item><with|font-series|bold|Step7.> Search for repeated <math|indexes>,
    <math|loop<around*|[|indexes|]>>;

    <item><with|font-series|bold|Step8.> Convert these repeated indexes to be
    for loops;

    <item><with|font-series|bold|Step9.> Output these codes into disk.\ 
  </itemize>

  \;

  <with|font-series|bold|The position of pointer:>

  <with|font-series|bold|Line_split>

  <\eqnarray*>
    <tformat|<table|<row|<cell|<around*|[|0,1|]>>|<cell|\<rightarrow\>>|<cell|<rprime|'>=<rprime|'>>>|<row|<cell|<around*|[|2,position1|]>>|<cell|\<rightarrow\>>|<cell|<rprime|'>+<rprime|'>>>|<row|<cell|<around*|[|position1+1,position2|]>>|<cell|\<rightarrow\>>|<cell|<rprime|'>-<rprime|'>>>|<row|<cell|<around*|[|position2+1,position3|]>>|<cell|\<rightarrow\>>|<cell|<rprime|'>\<ast\><rprime|'>>>>>
  </eqnarray*>

  <with|font-series|bold|Qusetion:> <math|How about there is no
  <rprime|'>-<rprime|'>>?

  It's okay for this condition.

  <with|font-series|bold|Note that we shouldn't split the our string twice
  for a specific character.>

  For example, if we already split <math|a=b*\<ast\>c+d> as <math|a and
  =b\<ast\>c+d>, If we split <math|=b\<ast\>c+d> according to ``='' again we
  would get <math|b\<ast\>c+d>, which is not we want.

  <with|font-series|bold|Note that If we want to interpret
  <math|a=<around*|(|b+c|)>*\<ast\>d>, then we don't have to deal with
  bracket and just regard <math|<left|(>> and <math|<right|)>> as variable
  that don't have indexes. For simplicity we would like to write it as
  <math|a=<left|(>> <math|b+c> )*d. Note that there is a space between
  <math|<left|(>> and <math|b>.>

  <with|font-series|bold|Example:>

  <\itemize>
    <item>Suppose we have an expression <math|C<around*|[|t|]>=\<Phi\><around*|[|p,t,\<alpha\>,\<beta\>,a,b|]>\<ast\>g<around*|[|\<beta\>,\<alpha\><rprime|'>|]>\<ast\>\<tau\><around*|[|t,t<rprime|'>,\<alpha\><rprime|'>,\<alpha\>,b,c|]>>

    <item><with|font-series|bold|Step1.> <with|font-shape|italic|split
    ``=''><math|\<Rightarrow\>> char * line1=<math|<around*|[|C,=\<Phi\>\<ast\>g\<ast\>\<tau\>|]>>;

    <item><with|font-series|bold|Step2.> <with|font-shape|italic|split
    ``+''><math|\<Rightarrow\>>char *lin2_1=[C], char *
    line2_2=[<math|=\<Phi\>\<ast\>g\<ast\>\<tau\>>];

    <item><with|font-series|bold|Step3.> <with|font-shape|italic|split ``-''>
    <math|\<Rightarrow\>> char *line3_1=[C], char
    *line3_2=[<math|=\<Phi\>\<ast\>g\<ast\>\<tau\>>];

    <item><with|font-series|bold|Step4.> <with|font-shape|italic|split> ``*''
    <math|\<Rightarrow\>> char *line4_1=[C],char
    *line4_2=[<math|=\<Phi\>>],char *line4_3=[<math|\<ast\>g>], char
    *line4_4=[<math|\<ast\>\<tau\>>];

    <item><with|font-series|bold|Step5.> split ``[`` <math|\<Rightarrow\>>
    <math|\<Phi\><around*|[|p,t,\<alpha\>,\<beta\>,a,b|]>\<rightarrow\>char
    \<ast\>Var=<around*|[|\<Phi\>,<around*|[|p,t,\<alpha\>,\<beta\>,a,<rprime|''>b|]><rprime|''>|]><right|]>>;

    <item><with|font-series|bold|Step6>. <with|font-shape|italic|split ``]''>
    <math|\<Rightarrow\>> char *Var=[<math|\<Phi\>,<around*|[|p,t,\<alpha\>,\<beta\>,a,b|]>>];

    <item><with|font-series|bold|Step7.><with|font-shape|italic|split ``,''>
    <math|\<Rightarrow\>> char *line7=[<math|\<Phi\>,p,t,\<alpha\>,\<beta\>,a,b>];

    <item><with|font-series|bold|Step8.><with|font-shape|italic|Searching
    repeated indexes.> <with|font-series|bold|Note that I \ will ignore this
    step because there is no necessary to write the for loop explicitly. I
    can manually write these loop.>

    <item><with|font-series|bold|Step8.> Write the
    <math|<around*|[|\<Phi\>,p,t,\<alpha\>,\<beta\>,a,b|]>\<Rightarrow\>\<Phi\><around*|[|p|]><around*|[|t|]><around*|[|\<alpha\>|]><around*|[|\<beta\>|]><around*|[|a|]><around*|[|b|]>>;

    <item><with|font-series|bold|Step9.> <with|font-shape|italic|printf(``%s'',\<Phi\>)>.
  </itemize>

  <with|font-series|bold|Note that we can write a for loop for each split.>

  <subsubsection|CUDA Version>

  \;

  Our ultimate goal is to get the cuda version code of contraction. Because
  cuda code is quite cumbersome It's better to generate it automatically.

  Because of the requirements of parallel programming, the indexes of cuda
  array is more complicated than cpu code.\ 

  <\eqnarray*>
    <tformat|<table|<row|<cell|Vector<around*|[|o|]><around*|[|t<rsub|snk>|]><around*|[|c<rsub|1>|]><around*|[|c<rsub|2>|]>>|<cell|\<longrightarrow\>>|<cell|Vector<around*|[|o\<ast\>nt\<ast\>num<rsub|vecs>\<ast\>num<rsub|vecs>+t<rsub|snk>\<ast\>num<rsub|vecs>\<ast\>num<rsub|vecs>+c<rsub|1>\<ast\>num<rsub|vecs>+c<rsub|2>|]>>>|<row|<cell|gamma<around*|[|\<alpha\>|]><around*|[|\<beta\>|]>>|<cell|\<longrightarrow\>>|<cell|gamma<around*|[|\<alpha\>\<ast\>Ns+\<beta\>|]>>>|<row|<cell|corr<around*|[|o|]><left|[>t<rsub|src><left|]><around*|[|t|]>>|<cell|\<longrightarrow\>>|<cell|corr<around*|[|o\<ast\>timeslice\<ast\>nt+t<rsub|src>\<ast\>nt+t|]>>>|<row|<cell|peram<around*|[|t<rsub|src>|]><around*|[|t|]><around*|[|s<rsub|2>|]><around*|[|s<rsub|3>|]><around*|[|c<rsub|2>|]><around*|[|c<rsub|3>|]>>|<cell|\<longrightarrow\>>|<cell|peram<around*|[|t<rsub|src>\<ast\>nt\<ast\>Ns\<ast\>Ns\<ast\>num<rsub|vecs>\<ast\>num<rsub|vecs>+t\<ast\>Ns\<ast\>Ns\<ast\>num<rsub|vecs>\<ast\>num<rsub|vecs>+s<rsub|2>\<ast\>Ns\<ast\>Num<rsub|vecs>\<ast\>Num<rsub|vecs>+s<rsub|3>\<ast\>Num<rsub|vecs>\<ast\>Num<rsub|vecs>+c<rsub|2>\<ast\>Num<rsub|vecs>|]>>>>>
  </eqnarray*>

  Note that we have four kinds of variables. They have two,three,four,six
  indexes.

  <math|\<Longrightarrow\>>\ 

  We need to define an array for each variable to store these constants.

  For example, <math|gamma<around*|[|\<alpha\>|]><around*|[|\<beta\>|]>>
  should define an array <math|g<rsub|array><around*|[|0|]>=1,g<rsub|array><around*|[|1|]>=Ns.>

  Then <math|gamma<around*|[|\<alpha\>|]><around*|[|\<beta\>|]>\<longrightarrow\>gamma<around*|[|\<alpha\>\<ast\>g<rsub|array><around*|[|1|]>+\<beta\>\<ast\>g<rsub|array><around*|[|0|]>|]>>.

  <with|font-series|bold|Question: How about hermtian conjugate ?>

  \;

  <section|CUDA BY EXAMPLE>

  \;

  <section|OPENQCD>

  \;

  <subsection|Reading PLAN>

  \;

  <with|font-series|bold|Questions:>

  <\itemize>
    <item><with|font-series|bold|Q1.> This package seems to be quite large
    for me, how to divide it into little parts ?

    <item><with|font-series|bold|Q2.> Where we can start from ?

    <item><with|font-series|bold|Q3.> How to continue with this package if we
    finished reading this package ?

    <item><with|font-series|bold|Q4.> How many times it should cost ?
  </itemize>

  \;

  <with|font-series|bold|Solutions:>

  <\itemize>
    <item><with|font-series|bold|S1.> Fistly, we need to split this package
    into several parts according to the directories in module directory. And
    we need to test these codes for each parts; Secondly, we should make our
    code has the ability to be tested easily,<with|font-series|bold|Fortunately,
    the devel directory of OpenQCD can be tested seperately>;

    <item><with|font-series|bold|S2.> It seems to be better for us to hack
    this package by start from some specific direction. For me, I'd like to
    start from HMC program.

    <item><with|font-series|bold|S3.> We can implement some algorithms in
    this package and write a cuda version of this package. However, this is
    not the thing that we should consider right now.

    <item><with|font-series|bold|S4.> I am totally a new commer both for
    lattice and programming. OpenQCD may have <math|30> thousand lines. For a
    program that almost have <math|300> lines I would cost 7 days to read it.
    So It would spend me <math|<frac|30000|300>=100> days to read the OPENQCD
    package. To account some unexpected difficulties, It may take 200 days to
    read this package.\ 
  </itemize>

  <subsection|<with|font-shape|italic|ym1.c>>

  <subsubsection|<with|font-shape|italic|main()> function>

  <with|font-series|bold|STEPS:>

  <\itemize>
    <item><with|font-series|bold|Step1.> <with|font-shape|italic|MPI_Init(&argc,&argv)>;

    <item><with|font-series|bold|Step2.> <with|font-shape|italic|read_infile(&argc,&argv);>

    <item><with|font-series|bold|Step3.> <with|font-shape|italic|check_machine();>

    <item><with|font-series|bold|Step4.> <with|font-shape|italic|Init field.
    init_rng(icnfg); init_ud();>

    <item><with|font-series|bold|Step5.><with|font-shape|italic|Forloop,for(n=0;(iend==0)&&(n\<less\>ntr);n++);
    run_hmc(act0,act1);save_msdat(n,wtms,wtmsall);>

    <item><with|font-series|bold|Step6.> <with|font-shape|italic|save_flds(icnfg);>
  </itemize>

  <subsubsection|hmc.c<math|\<longrightarrow\>> run_hmc()>

  \;

  <with|font-shape|italic|int run_hmc(qflt *act0, qflt *act1);>

  <with|font-shape|italic|return value is 1 or 0. 1<math|\<longrightarrow\>>
  configuration accepted. 0 <math|\<longrightarrow\>> configuration is
  rejected.>

  <\itemize>
    <item><with|font-shape|italic|act[0]> action of the momentum field;

    <item><with|font-shape|italic|act[1]> \ gauge field action;

    <item><with|font-shape|italic|act[2..n]> pseudo-fermion action number n.
  </itemize>

  <with|font-series|bold|Su3_dble:>

  <with|font-shape|italic|typedef struct{ complex_dble
  c11,c12,c13,c21,c22,c23,c31,c32,c33} su3_dble;>

  \;

  Obviously, <with|font-shape|italic|su3_dble> declare a complex
  <math|3\<times\>3> array.

  <\eqnarray*>
    <tformat|<table|<row|<cell|<matrix|<tformat|<table|<row|<cell|c<rsub|11>>|<cell|c<rsub|12>>|<cell|c<rsub|13>>>|<row|<cell|c<rsub|21>>|<cell|c<rsub|22>>|<cell|c<rsub|23>>>|<row|<cell|c<rsub|31>>|<cell|c<rsub|32>>|<cell|c<rsub|33>>>>>>>|<cell|>|<cell|>>>>
  </eqnarray*>

  \;
</body>

<initial|<\collection>
</collection>>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|1>>
    <associate|auto-10|<tuple|4.2.1|?>>
    <associate|auto-11|<tuple|4.2.2|?>>
    <associate|auto-2|<tuple|1.1|1>>
    <associate|auto-3|<tuple|2|1>>
    <associate|auto-4|<tuple|2.1|2>>
    <associate|auto-5|<tuple|2.1.1|4>>
    <associate|auto-6|<tuple|3|4>>
    <associate|auto-7|<tuple|4|?>>
    <associate|auto-8|<tuple|4.1|?>>
    <associate|auto-9|<tuple|4.2|?>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|1<space|2spc>SHELL
      > <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.5fn>

      <with|par-left|<quote|1tab>|1.1<space|2spc>Basic Function
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-2>>

      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|2<space|2spc>My
      First Own Project: <with|font-series|<quote|bold>|Assistant>>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-3><vspace|0.5fn>

      <with|par-left|<quote|1tab>|2.1<space|2spc>Assistant for Contraction
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-4>>

      <with|par-left|<quote|2tab>|2.1.1<space|2spc>CUDA Version
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-5>>

      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|3<space|2spc>OPENQCD>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-6><vspace|0.5fn>

      <with|par-left|<quote|1tab>|3.1<space|2spc>Reading PLAN
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-7>>

      <with|par-left|<quote|1tab>|3.2<space|2spc><with|font-shape|<quote|italic>|ym1.c>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-8>>

      <with|par-left|<quote|2tab>|3.2.1<space|2spc><with|font-shape|<quote|italic>|main()>
      function <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-9>>

      <with|par-left|<quote|2tab>|3.2.2<space|2spc>hmc.c<with|mode|<quote|math>|\<longrightarrow\>>
      run_hmc() <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-10>>
    </associate>
  </collection>
</auxiliary>