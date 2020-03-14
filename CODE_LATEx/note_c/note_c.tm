<TeXmacs|1.99.2>

<style|article>

<\body>
  <doc-data|<doc-title|NOTES OF C PROGRMMING>>

  <section|POINTERS>

  <\itemize>
    <item>To use <with|font-shape|italic|strcat, strcpy,strtok> function you
    should include <with|font-shape|italic|<math|<around|\<langle\>|string.h|\<rangle\>>>>.
    And pointers shouldn't be used in these function until you
    <math|malloc<around*|(|sizeof<around*|(|char|)>\<ast\>buffsize|)>>. Also
    note that one pointer <math|char \<ast\>\<ast\>
    p=malloc<around*|(|sizeof<around*|(|char\<ast\>|)>\<ast\>bufsize|)>> also
    can't be used in these functions because you didn't malloc for
    <with|font-shape|italic|char> instead you malloc for <text|character
    pointer,char<math|\<ast\>>>.

    \ \ \ 
  </itemize>

  <section|FUNCTIONS>

  <\itemize>
    <item>Some repeated operation should be abstract as an function. In this
    way it's more convenient for programming and debuging.

    <item>If there is a head file, for example <with|font-shape|italic|foo.h
    and foo.c>, when we compile the <with|font-shape|italic|main.c> we should
    use <with|font-shape|italic|gcc -o appname foo.c main.c>;

    <item>I wrote a <with|font-shape|italic|readline> function. I use
    <with|font-shape|italic|char *single_line> to store a single line. And I
    found that then <math|<rprime|''>\<backslash\>n<rprime|''>> should be
    store as <with|font-shape|italic|single_line[n]='<math|\<backslash\>0>'>.
    Otherwise, some mistake would arise.

    <item>If a function want to return multiple variables, we can use
    pointers. <with|font-series|bold|Note> that you should note the
    initialization of pointers. <with|font-series|bold|Note that > these
    pointers defined in the function can't pass to these pointers defined out
    of the function, for example, <with|font-shape|italic|c=a.> Where <math|c
    > is a pointer out of function and <math|a> is pointer inside the
    function. <with|font-series|bold|The only way to pass these pointers that
    inside the function is <with|font-shape|italic|return p;>>. Then we can
    us <with|font-shape|italic|c=func(args)> to get the return pointers.

    <item><with|font-shape|italic|static declarization will rememenber it's
    value. <with|font-series|bold|static int a=6.> suppose that you declare
    your static variable inside the function. Then you can get your variable.
    If you want to redeclare your static variable, the processer would ignore
    it. >

    <item><with|font-shape|italic|math.h> \ \ gcc will not automatically link
    to math library if you used it in your header file. It would warn
    ``undefined reference to sqrt, cos ...''. You need to use <math|-lm>
    option while compiling. \ 
  </itemize>

  \;
</body>

<initial|<\collection>
</collection>>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|?>>
    <associate|auto-2|<tuple|2|?>>
    <associate|auto-3|<tuple|3|?>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|1<space|2spc>POINTERS>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.5fn>

      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|2<space|2spc>FUNCTIONS>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-2><vspace|0.5fn>
    </associate>
  </collection>
</auxiliary>