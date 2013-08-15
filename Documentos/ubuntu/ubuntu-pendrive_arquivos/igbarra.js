/* © Copyright 2000-2007, Internet Group - Portais: iG, iBest e BrTurbo */
/* powered by: wrenzi, llemos, dtrindade & alaky */

// Funções...
function _$getPortal() { if(self != top) { if(top.brturbo) { _$portal = 2; } else if(top.ibest) { _$portal = 3; } else { _$portal = 1; } } else { _$portal = 1; } return _$portal;}
function abrePopGenericoIg(url, largura, altura) { window.open(url, "popgenericoiG", "scrollbars=0, width=" + largura + ", height=" + altura);}
function buscaiG(frm1){ if(document.frm1.q.value == "Faça sua busca" || document.frm1.q.value == "Fa&ccedil;a sua busca"){ alert("Digite uma consulta antes de acionar a busca"); }else{ window.open("http://busca.igbusca.com.br/app/search?q="+escape(frm1.q.value)+"&o=BARRAIG"); } return false;}

/* resgata site */
var locrz = location.href;
var rgcrz = "[\?&]codsit=([^&#]*)";
var rserz = (new RegExp(rgcrz)).exec(locrz);
var fnrrz = (rserz == null ? (locrz.indexOf("parceiros_regionais/parceiros_regionais") != -1 ? "51" : "") : rserz[1]);

/* form */
var fbcrz = '	<div class="barraForm"><form onsubmit="return buscaiG(this);" method="get">'+
          	'		<fieldset>'+
		  	'		<input id="q" name="q" value="Fa&ccedil;a sua busca" onFocus="this.value=\'\'" onBlur="if(this.value==\'\'){this.value=\'Fa&ccedil;a sua busca\'}" class="barra_busca">'+
          	' 		<input class="barra_botao" type="image" src="http://images.ig.com.br/barraig/barra_botao.gif" value="Buscar">'+
          	'		</fieldset> '+
          	'	</form></div>';

/* links */
var ldfrz = '<div class="barraLinksIG"><ul>'+
          	'		<li><a href="http://www.ig.com.br/acesso/" target="_top">Assine</a></li>'+
          	'		<li><a href="http://portal.ig.com.br/acesso_email.html" target="_top">E-mail</a></li>'+
          	'		<li><a href="https://cadastro.ig.com.br/atendimento/index.jsp" target="_top">SAC</a></li>'+
          	'		<li class=last><a href="http://www.ig.com.br/indice/" target="_top">Canais</a></li>'+
          	'</ul></div>';

/* portais */
var lptrz = '<div class="barraLogoIBEST"><a href="http://www.ibest.com.br/"><img src="http://images.ig.com.br/barraig/barra_ibest.gif" alt="iBest" /><!-- --></a></div>'+
         	'<div class="barraLogoBRT"><a href="http://www.brturbo.com.br/"><img src="http://images.ig.com.br/barraig/barra_brturbo.gif" alt="brTurbo" /><!-- --></a></div>';


/* busca */
document.write('<scr'+'ipt type="text/javascript">function buscaiG(frm1){ if(frm1.q.value == "Fa&ccedil;a sua busca" || frm1.q.value == "Faça sua busca" ){ alert("Digite uma consulta antes de acionar a busca"); }else{ window.open("http://busca.igbusca.com.br/app/search?q="+escape(frm1.q.value)+"&o=BARRAIG"); } return false;}</scr'+'ipt>');

/* canais */
document.write('<scr'+'ipt type="text/javascript" src="http://images.ig.com.br/novoscanais/js/generico.js"></scr'+'ipt>');

/* estilo */
document.write('<link rel="stylesheet" type="text/css" href="http://images.ig.com.br/barraig/v8/css/barra'+fnrrz+'.css" />');

/* barra */
document.write('<scr'+'ipt type="text/javascript" src="http://images.ig.com.br/barraig/v8/js/barra'+fnrrz+'.js"></scr'+'ipt>');