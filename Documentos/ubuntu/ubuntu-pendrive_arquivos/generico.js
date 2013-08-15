function _$redCnlNC($form, $value) {
	$form.action = $value;
	$form.submit();
}

function getOptCnsHTML(){

var html = '<form name="canais" method="post"  target="_blank">'+
	 '<select class="outrosCanais" onchange="_$redCnlNC(this.form,this.value)">'+
	 '<option>Outros Canais<\/option>'+
	 '<option value="http://astral.ig.com.br">Astral<\/option>'+
	 '<option value="http://beleza.ig.com.br">Beleza<\/option>'+
	 '<option value="http://ig.vrum.com.br">Carros<\/option>'+
	 '<option value="http://casa.ig.com.br">Casa<\/option>'+
   '<option value="http://igcelular.ig.com.br">Celular<\/option>'+
	 '<option value="http://criancas.ig.com.br">Crianças<\/option>'+
	 '<option value="http://ultimosegundo.ig.com.br/cultura/">Cultura<\/option>'+
	 '<option value="http://baixaki.ig.com.br">Downloads<\/option>'+
	 '<option value="http://ultimosegundo.ig.com.br/economia">Economia<\/option>'+
	 '<option value="http://educacao.ig.com.br/">Educação<\/option>'+ 
	 '<option value="http://www.manager.com.br/candidatos/vantagens_candidatos_canal_ig_proc.php">Empregos<\/option>'+
	 '<option value="http://ultimosegundo.ig.com.br/esportes">Esportes<\/option>'+
	 '<option value="http://estilo.ig.com.br">Estilo<\/option>'+
	 '<option value="http://eunaweb.ig.com.br">Eu na web<\/option>'+
	 '<option value="http://gente.ig.com.br">Gente<\/option>'+
	 '<option value="http://www.ig.com.br/sexo/gay">GLS<\/option>'+
	 '<option value="http://gourmet.ig.com.br">Gourmet<\/option>'+
	 '<option value="http://www.igempresas.ig.com.br/acessoigvip">Empresas<\/option>'+
	 '<option value="http://arenaturbo.ig.com.br/">Jogos<\/option>'+
	 '<option value="http://jovem.ig.com.br">Jovem<\/option>'+
	 '<option value="http://moda.ig.com.br">Moda<\/option>'+
	 '<option value="http://delas.ig.com.br">Mulher<\/option>'+
	 '<option value="http://igmusica.ig.com.br">Musica<\/option>'+
	 '<option value="http://poupaclique.ig.com.br">Poupa Clique<\/option>'+
	 '<option value="http://www.ig.com.br/paginas/revistas/">Revistas<\/option>'+
	 '<option value="http://ultimosegundo.ig.com.br/brasil/">Saúde<\/option>'+
	 '<option value="http://www.ig.com.br/sexo/sensual">Sensual<\/option>'+
	 '<option value="http://igprodutos.ig.com.br">Serviços<\/option>'+
	 '<option value="http://www.ig.com.br/sexo">Sexo<\/option>'+
	 '<option value="http://igshopping.ig.com.br">Shopping<\/option>'+
	 '<option value="http://tecnologia.ig.com.br">Tecnologia<\/option>'+
	 '<option value="http://turismo.ig.com.br">Turismo<\/option>'+
	 '<option value="http://megaplayer.ig.com.br">Vídeos<\/option>'+	 
	 '<option value="http://www.ig.com.br/indice">Todos os sites<\/option>'+	 
	 '<\/select>'+
	 '<\/form>';
	return html;
}

function escolhaCanal(){
	document.write(getOptCnsHTML());
}

function outroscanais(){
  escolhaCanal();
}

function _s(e){
	if(typeof(e)=='undefined')var e=window.event
	s=e.target?e.target:e.srcElement
	return (s.nodeType==3)?s.parentNode:s;
}

function vldBusca(e) {
	fb=_s(e);
	fb=(fb.type!=undefined)?fb.parentNode.parentNode:fb;
	if(fb.q.value == '') {
		alert('Digite uma consulta antes de acionar a busca');
		return false;
	}
}

if(window.addEventListener) { // Mz
    window.addEventListener("load", function() {
        if(document.getElementById("busca_google") != null) {
            document.getElementById("busca_google").onsubmit=vldBusca;
		}
	}, false);
} else if(window.attachEvent) {
    window.attachEvent("onload", function() {
        if(document.getElementById("busca_google") != null) {
            document.getElementById("busca_google").onsubmit=vldBusca;
		}
	});
}

function animeFlash(){document.getElementById("animacaoflash").style.clip="rect(0px 620px 481px 0px)"}
function closeFlash(){document.getElementById("animacaoflash").style.clip="rect(0px 619px 224px 0px)"}

/*=================FotoSHOW======================*/
function openGalPop(url){
	if(url.indexOf("/fotoshow/")>-1){
		if((detectOS()=='Windows')&&(detectBrowser()=='IE')){
			FullScreen(url);
		}else{
			onload=FullScreen(url);
		}
	}else if(url.indexOf("ultimosegundo")>-1){
		window.open(url,'_self')
	}else{
		window.open(url,'Galeria','toolbar=0,location=0,directories=0,status=yes,menubar=0,scrollbars=yes,resizable=0,width=796,height=546,top=100,left=50')
	}
}
var swfobject=function(){var Z="undefined",P="object",B="Shockwave Flash",h="ShockwaveFlash.ShockwaveFlash",W="application/x-shockwave-flash",K="SWFObjectExprInst",G=window,g=document,N=navigator,f=[],H=[],Q=null,L=null,T=null,S=false,C=false;var a=function(){var l=typeof g.getElementById!=Z&&typeof g.getElementsByTagName!=Z&&typeof g.createElement!=Z&&typeof g.appendChild!=Z&&typeof g.replaceChild!=Z&&typeof g.removeChild!=Z&&typeof g.cloneNode!=Z,t=[0,0,0],n=null;if(typeof N.plugins!=Z&&typeof N.plugins[B]==P){n=N.plugins[B].description;if(n){n=n.replace(/^.*\s+(\S+\s+\S+$)/,"$1");t[0]=parseInt(n.replace(/^(.*)\..*$/,"$1"),10);t[1]=parseInt(n.replace(/^.*\.(.*)\s.*$/,"$1"),10);t[2]=/r/.test(n)?parseInt(n.replace(/^.*r(.*)$/,"$1"),10):0}}else{if(typeof G.ActiveXObject!=Z){var o=null,s=false;try{o=new ActiveXObject(h+".7")}catch(k){try{o=new ActiveXObject(h+".6");t=[6,0,21];o.AllowScriptAccess="always"}catch(k){if(t[0]==6){s=true}}if(!s){try{o=new ActiveXObject(h)}catch(k){}}}if(!s&&o){try{n=o.GetVariable("$version");if(n){n=n.split(" ")[1].split(",");t=[parseInt(n[0],10),parseInt(n[1],10),parseInt(n[2],10)]}}catch(k){}}}}var v=N.userAgent.toLowerCase(),j=N.platform.toLowerCase(),r=/webkit/.test(v)?parseFloat(v.replace(/^.*webkit\/(\d+(\.\d+)?).*$/,"$1")):false,i=false,q=j?/win/.test(j):/win/.test(v),m=j?/mac/.test(j):/mac/.test(v);return{w3cdom:l,pv:t,webkit:r,ie:i,win:q,mac:m}}();var e=function(){if(!a.w3cdom){return}J(I);if(a.ie&&a.win){try{g.write("<script id=__ie_ondomload defer=true src=//:><\/script>");var i=c("__ie_ondomload");if(i){i.onreadystatechange=function(){if(this.readyState=="complete"){this.parentNode.removeChild(this);V()}}}}catch(j){}}if(a.webkit&&typeof g.readyState!=Z){Q=setInterval(function(){if(/loaded|complete/.test(g.readyState)){V()}},10)}if(typeof g.addEventListener!=Z){g.addEventListener("DOMContentLoaded",V,null)}M(V)}();function V(){if(S){return}if(a.ie&&a.win){var m=Y("span");try{var l=g.getElementsByTagName("body")[0].appendChild(m);l.parentNode.removeChild(l)}catch(n){return}}S=true;if(Q){clearInterval(Q);Q=null}var j=f.length;for(var k=0;k<j;k++){f[k]()}}function J(i){if(S){i()}else{f[f.length]=i}}function M(j){if(typeof G.addEventListener!=Z){G.addEventListener("load",j,false)}else{if(typeof g.addEventListener!=Z){g.addEventListener("load",j,false)}else{if(typeof G.attachEvent!=Z){G.attachEvent("onload",j)}else{if(typeof G.onload=="function"){var i=G.onload;G.onload=function(){i();j()}}else{G.onload=j}}}}}function I(){var l=H.length;for(var j=0;j<l;j++){var m=H[j].id;if(a.pv[0]>0){var k=c(m);if(k){H[j].width=k.getAttribute("width")?k.getAttribute("width"):"0";H[j].height=k.getAttribute("height")?k.getAttribute("height"):"0";if(O(H[j].swfVersion)){if(a.webkit&&a.webkit<312){U(k)}X(m,true)}else{if(H[j].expressInstall&&!C&&O("6.0.65")&&(a.win||a.mac)){D(H[j])}else{d(k)}}}}else{X(m,true)}}}function U(m){var k=m.getElementsByTagName(P)[0];if(k){var p=Y("embed"),r=k.attributes;if(r){var o=r.length;for(var n=0;n<o;n++){if(r[n].nodeName.toLowerCase()=="data"){p.setAttribute("src",r[n].nodeValue)}else{p.setAttribute(r[n].nodeName,r[n].nodeValue)}}}var q=k.childNodes;if(q){var s=q.length;for(var l=0;l<s;l++){if(q[l].nodeType==1&&q[l].nodeName.toLowerCase()=="param"){p.setAttribute(q[l].getAttribute("name"),q[l].getAttribute("value"))}}}m.parentNode.replaceChild(p,m)}}function F(i){if(a.ie&&a.win&&O("8.0.0")){G.attachEvent("onunload",function(){var k=c(i);if(k){for(var j in k){if(typeof k[j]=="function"){k[j]=function(){}}}k.parentNode.removeChild(k)}})}}function D(j){C=true;var o=c(j.id);if(o){if(j.altContentId){var l=c(j.altContentId);if(l){L=l;T=j.altContentId}}else{L=b(o)}if(!(/%$/.test(j.width))&&parseInt(j.width,10)<310){j.width="310"}if(!(/%$/.test(j.height))&&parseInt(j.height,10)<137){j.height="137"}g.title=g.title.slice(0,47)+" - Flash Player Installation";var n=a.ie&&a.win?"ActiveX":"PlugIn",k=g.title,m="MMredirectURL="+G.location+"&MMplayerType="+n+"&MMdoctitle="+k,p=j.id;if(a.ie&&a.win&&o.readyState!=4){var i=Y("div");p+="SWFObjectNew";i.setAttribute("id",p);o.parentNode.insertBefore(i,o);o.style.display="none";G.attachEvent("onload",function(){o.parentNode.removeChild(o)})}R({data:j.expressInstall,id:K,width:j.width,height:j.height},{flashvars:m},p)}}function d(j){if(a.ie&&a.win&&j.readyState!=4){var i=Y("div");j.parentNode.insertBefore(i,j);i.parentNode.replaceChild(b(j),i);j.style.display="none";G.attachEvent("onload",function(){j.parentNode.removeChild(j)})}else{j.parentNode.replaceChild(b(j),j)}}function b(n){var m=Y("div");if(a.win&&a.ie){m.innerHTML=n.innerHTML}else{var k=n.getElementsByTagName(P)[0];if(k){var o=k.childNodes;if(o){var j=o.length;for(var l=0;l<j;l++){if(!(o[l].nodeType==1&&o[l].nodeName.toLowerCase()=="param")&&!(o[l].nodeType==8)){m.appendChild(o[l].cloneNode(true))}}}}}return m}function R(AE,AC,q){var p,t=c(q);if(typeof AE.id==Z){AE.id=q}if(a.ie&&a.win){var AD="";for(var z in AE){if(AE[z]!=Object.prototype[z]){if(z=="data"){AC.movie=AE[z]}else{if(z.toLowerCase()=="styleclass"){AD+=' class="'+AE[z]+'"'}else{if(z!="classid"){AD+=" "+z+'="'+AE[z]+'"'}}}}}var AB="";for(var y in AC){if(AC[y]!=Object.prototype[y]){AB+='<param name="'+y+'" value="'+AC[y]+'" />'}}t.outerHTML='<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000"'+AD+">"+AB+"</object>";F(AE.id);p=c(AE.id)}else{if(a.webkit&&a.webkit<312){var AA=Y("embed");AA.setAttribute("type",W);for(var x in AE){if(AE[x]!=Object.prototype[x]){if(x=="data"){AA.setAttribute("src",AE[x])}else{if(x.toLowerCase()=="styleclass"){AA.setAttribute("class",AE[x])}else{if(x!="classid"){AA.setAttribute(x,AE[x])}}}}}for(var w in AC){if(AC[w]!=Object.prototype[w]){if(w!="movie"){AA.setAttribute(w,AC[w])}}}t.parentNode.replaceChild(AA,t);p=AA}else{var s=Y(P);s.setAttribute("type",W);for(var v in AE){if(AE[v]!=Object.prototype[v]){if(v.toLowerCase()=="styleclass"){s.setAttribute("class",AE[v])}else{if(v!="classid"){s.setAttribute(v,AE[v])}}}}for(var u in AC){if(AC[u]!=Object.prototype[u]&&u!="movie"){E(s,u,AC[u])}}t.parentNode.replaceChild(s,t);p=s}}return p}function E(k,i,j){var l=Y("param");l.setAttribute("name",i);l.setAttribute("value",j);k.appendChild(l)}function c(i){return g.getElementById(i)}function Y(i){return g.createElement(i)}function O(k){var j=a.pv,i=k.split(".");i[0]=parseInt(i[0],10);i[1]=parseInt(i[1],10);i[2]=parseInt(i[2],10);return(j[0]>i[0]||(j[0]==i[0]&&j[1]>i[1])||(j[0]==i[0]&&j[1]==i[1]&&j[2]>=i[2]))?true:false}function A(m,j){if(a.ie&&a.mac){return}var l=g.getElementsByTagName("head")[0],k=Y("style");k.setAttribute("type","text/css");k.setAttribute("media","screen");if(!(a.ie&&a.win)&&typeof g.createTextNode!=Z){k.appendChild(g.createTextNode(m+" {"+j+"}"))}l.appendChild(k);if(a.ie&&a.win&&typeof g.styleSheets!=Z&&g.styleSheets.length>0){var i=g.styleSheets[g.styleSheets.length-1];if(typeof i.addRule==P){i.addRule(m,j)}}}function X(k,i){var j=i?"visible":"hidden";if(S){c(k).style.visibility=j}else{A("#"+k,"visibility:"+j)}}return{registerObject:function(l,i,k){if(!a.w3cdom||!l||!i){return}var j={};j.id=l;j.swfVersion=i;j.expressInstall=k?k:false;H[H.length]=j;X(l,false)},getObjectById:function(l){var i=null;if(a.w3cdom&&S){var j=c(l);if(j){var k=j.getElementsByTagName(P)[0];if(!k||(k&&typeof j.SetVariable!=Z)){i=j}else{if(typeof k.SetVariable!=Z){i=k}}}}return i},embedSWF:function(n,u,r,t,j,m,k,p,s){if(!a.w3cdom||!n||!u||!r||!t||!j){return}r+="";t+="";if(O(j)){X(u,false);var q=(typeof s==P)?s:{};q.data=n;q.width=r;q.height=t;var o=(typeof p==P)?p:{};if(typeof k==P){for(var l in k){if(k[l]!=Object.prototype[l]){if(typeof o.flashvars!=Z){o.flashvars+="&"+l+"="+k[l]}else{o.flashvars=l+"="+k[l]}}}}J(function(){R(q,o,u);if(q.id==u){X(u,true)}})}else{if(m&&!C&&O("6.0.65")&&(a.win||a.mac)){X(u,false);J(function(){var i={};i.id=i.altContentId=u;i.width=r;i.height=t;i.expressInstall=m;D(i)})}}},getFlashPlayerVersion:function(){return{major:a.pv[0],minor:a.pv[1],release:a.pv[2]}},hasFlashPlayerVersion:O,createSWF:function(k,j,i){if(a.w3cdom&&S){return R(k,j,i)}else{return undefined}},createCSS:function(j,i){if(a.w3cdom){A(j,i)}},addDomLoadEvent:J,addLoadEvent:M,getQueryParamValue:function(m){var l=g.location.search||g.location.hash;if(m==null){return l}if(l){var k=l.substring(1).split("&");for(var j=0;j<k.length;j++){if(k[j].substring(0,k[j].indexOf("="))==m){return k[j].substring((k[j].indexOf("=")+1))}}}return""},expressInstallCallback:function(){if(C&&L){var i=c(K);if(i){i.parentNode.replaceChild(L,i);if(T){X(T,true);if(a.ie&&a.win){L.style.display="block"}}L=null;T=null;C=false}}}}}();function detectVersion()
{version=parseInt(navigator.appVersion);return version;}
function detectOS()
{if(navigator.userAgent.indexOf('Win')==-1){OS='Macintosh';}else{OS='Windows';}
return OS;}
function detectBrowser()
{if(navigator.appName.indexOf('Netscape')==-1){browser='IE';}
else{browser='Netscape';}
return browser;}
function FullScreen(url){var adjWidth;var adjHeight;if((detectOS()=='Macintosh')&&(detectBrowser()=='Netscape')){adjWidth=20;adjHeight=35;}
if((detectOS()=='Macintosh')&&(detectBrowser()=='IE')){adjWidth=20;adjHeight=35;winOptions='fullscreen=yes';}
if((detectOS()=='Windows')&&(detectBrowser()=='Netscape')){adjWidth=8;adjHeight=8;}
if((detectOS()=='Windows')&&(detectBrowser()=='IE')){adjWidth=8;adjHeight=88;winOptions='toolbar=yes';if((detectOS()=='Windows')&&(detectBrowser()=='Netscape')){adjWidth=8;adjHeight=8;}}
if(detectVersion()<4){self.location.href='oldbrowser.html';}else{var winWidth=screen.availWidth-adjWidth;var winHeight=screen.availHeight-adjHeight;if((detectOS()=='Windows')&&(detectBrowser()=='IE')){var winSize='width='+winWidth+',height='+winHeight+',location=yes,status=yes';var thewindow=window.open(url,'WindowName',winSize);thewindow.moveTo(0,0);}
else if((detectOS()=='Windows')&&(String(navigator.appVersion).indexOf('Chrome')!=-1)){var winSize='width='+winWidth+',height='+winHeight+',location=yes,status=yes';var thewindow=window.open(url,'WindowName',winSize);}
else{
	var winSize='width='+winWidth+',height='+winHeight;var thewindow=window.open(url,'WindowName',winSize);thewindow.moveTo(0,0);}}
}
/*=================FotoSHOW======================*/