/* <source lang=javascript> */
/* Any JavaScript here will be loaded for users using the MonoBook skin */

/** Anon tips and donation banner **************************
  *
  *  Descrição: Frases aleatórias que podem ser vistas por anônimos
  *  Autores: [[:en:User:Gmaxwell]] e [[:en:User:MZMcBride]]
  */

if(wgUserName == null) addOnloadHook((function (){
    var message=new Array();
        message[0]='Suas <a href="http://wikimediafoundation.org/wiki/Coleta_de_fundos" class="extiw" title="Coleta de fundos"><b>doações</b></a> manterão a Wikipédia ativa!';
        message[1]='<a href="http://pt.wikipedia.org/wiki/Ajuda:Guia_de_edição/Como_criar_uma_conta" class="extiw" title="Como criar uma conta"><b>Criando uma conta</b></a>, você terá <a href="http://pt.wikipedia.org/wiki/Wikipedia:Por_que_se_registrar%3F" class="extiw" title="Vantagens"><b>algumas vantagens</b></a>!';
        message[2]='<a href="http://wikimediafoundation.org/wiki/Coleta_de_fundos" class="extiw" title="Coleta de fundos"><b>Faça uma doação</b></a> para a Wikipédia dar um dom de conhecimento!';
        message[3]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:A_enciclopédia_livre" title="Saiba mais sobre a Wikipédia">Saiba mais sobre a Wikipédia.</a>';
        message[4]='A Wikipédia é mantida por pessoas como você. Por favor <a href="http://wikimediafoundation.org/wiki/Coleta_de_fundos" class="extiw" title="Coleta de fundos"><b>faça uma doação</b></a> hoje.';
        message[5]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:10_coisas_que_você_não_sabia_sobre_a_Wikipédia" title="As 10 coisas que você não sabia sobre a Wikipédia">As 10 coisas que você não sabia sobre a Wikipédia.</a>';
        message[6]='Ajude-nos a melhorar a Wikipédia <a href="http://wikimediafoundation.org/wiki/Coleta_de_fundos" class="extiw" title="Coleta de fundos"><b>fazendo uma doação</b></a>.';
        message[7]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:O_que_a_Wikipédia_não_é" title="O que a Wikipédia não é">O que a Wikipédia não é?</a>';
        message[8]='Ajude-nos a fornecer conteúdo gratuito para mundo <a href="http://wikimediafoundation.org/wiki/Coleta_de_fundos" class="extiw" title="Coleta de fundos"><b>doando hoje</b></a>!';
        message[9]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:Citando_a_Wikipédia" title="Saiba mais sobre como citar a Wikipédia">Saiba mais sobre como citar a Wikipédia.</a>';
        message[10]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:Por_que_eu_deveria_contribuir_para_a_Wikipédia" class="extiw" title="Por que contribuir para a Wikipédia?">Por que contribuir para a Wikipédia?</a>';
        message[11]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:Cinco_pilares" title="Os princípios fundadores da Wikipédia">Os princípios fundadores da Wikipédia</a>';
        message[12]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:Coisas_a_não_fazer" title="Coisas que não podem ser feitas de maneira alguma">Coisas que não podem ser feitas de maneira alguma.</a>';
        message[13]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:Como_contribuir_para_a_Wikipédia" title="Como contribuir para a Wikipédia">Quer contribuir para a Wikipédia?</a>';
        message[14]='<a href="http://pt.wikipedia.org/wiki/Wikipedia:Navegue" title="Navegue pela Wikipédia para encontrar mais informações">Navegue pela Wikipédia para encontrar mais informações.</a>';
        message[15]='Professor, utilize a Wikipédia em <a href="http://pt.wikipedia.org/wiki/Wikipedia:Projetos_escolares_e_universit%C3%A1rios" title="Projetos escolares e universitários">projetos escolares e universitários</a>.';
    var weightLimit = 9;
    var biasPercent = 0.6;
    var whichMessage = (Math.random() < biasPercent) ? weightLimit : message.length;
 
    whichMessage = Math.floor(Math.random() * whichMessage);
 
    var wrapper = document.getElementById("globalWrapper");
    if (wrapper) {
        var div = document.createElement('div');
        div.id = "anon-banner";
        div.className = "noprint";
        div.style.cssText = "position:absolute; z-index:40; left:155px; top:1px; clear:both; float:left; font-size:90%; font-style:italic; white-space:nowrap";
        div.innerHTML = message[whichMessage];
        wrapper.insertBefore(div, wrapper.firstChild);
    }
}));

/* </source> */