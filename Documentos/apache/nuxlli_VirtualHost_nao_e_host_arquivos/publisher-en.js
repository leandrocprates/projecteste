(function (){var g=true,k=null,l=false,n;var o=this;function aa(a,b){a=a.split(".");b=b||o;for(var c;c=a.shift();)if(b[c])b=b[c];else return k;return b}
function r(a){var b=typeof a;if(b=="object")if(a){if(a instanceof Array||!(a instanceof Object)&&Object.prototype.toString.call(a)=="[object Array]"||typeof a.length=="number"&&typeof a.splice!="undefined"&&typeof a.propertyIsEnumerable!="undefined"&&!a.propertyIsEnumerable("splice"))return"array";if(!(a instanceof Object)&&(Object.prototype.toString.call(a)=="[object Function]"||typeof a.call!="undefined"&&typeof a.propertyIsEnumerable!="undefined"&&!a.propertyIsEnumerable("call")))return"function"}else return"null";
else if(b=="function"&&typeof a.call=="undefined")return"object";return b}function ba(a){var b=r(a);return b=="array"||b=="object"&&typeof a.length=="number"}function s(a){return r(a)=="function"}function t(a){a=r(a);return a=="object"||a=="array"||a=="function"}function u(a){if(a.hasOwnProperty&&a.hasOwnProperty(v))return a[v];a[v]||(a[v]=++ca);return a[v]}var v="closure_hashCode_"+Math.floor(Math.random()*2147483648).toString(36),ca=0;
function da(a){var b=r(a);if(b=="object"||b=="array"){if(a.aa)return a.aa.call(a);b=b=="array"?[]:{};for(var c in a)b[c]=da(a[c]);return b}return a}function w(a,b){function c(){}c.prototype=b.prototype;a.Z=b.prototype;a.prototype=new c}function ea(a,b,c){if(a.indexOf)return a.indexOf(b,c);if(Array.indexOf)return Array.indexOf(a,b,c);for(c=c==k?0:c<0?Math.max(0,a.length+c):c;c<a.length;c++)if(c in a&&a[c]===b)return c;return-1}
function fa(a,b,c){if(a.forEach)a.forEach(b,c);else if(Array.forEach)Array.forEach(a,b,c);else for(var d=a.length,e=typeof a=="string"?a.split(""):a,f=0;f<d;f++)f in e&&b.call(c,e[f],f,a)}function ga(a,b){if(a.contains)return a.contains(b);return ea(a,b)>-1}function ha(a){if(r(a)=="array")return a.concat();else{for(var b=[],c=0,d=a.length;c<d;c++)b[c]=a[c];return b}}function ia(a){return/^[\s\xa0]*$/.test(a)}function ja(a){return a.replace(/^[\s\xa0]+|[\s\xa0]+$/g,"")}var ka=/^[a-zA-Z0-9\-_.!~*'()]*$/;
function la(a){a=String(a);if(!ka.test(a))return encodeURIComponent(a);return a}function x(a,b){if(b)return a.replace(ma,"&amp;").replace(na,"&lt;").replace(oa,"&gt;").replace(pa,"&quot;");else{if(!qa.test(a))return a;if(a.indexOf("&")!=-1)a=a.replace(ma,"&amp;");if(a.indexOf("<")!=-1)a=a.replace(na,"&lt;");if(a.indexOf(">")!=-1)a=a.replace(oa,"&gt;");if(a.indexOf('"')!=-1)a=a.replace(pa,"&quot;");return a}}var ma=/&/g,na=/</g,oa=/>/g,pa=/\"/g,qa=/[&<>\"]/;
function ra(a){if(y(a,"&"))return"document"in o&&!y(a,"<")?sa(a):ta(a);return a}function sa(a){var b=o.document.createElement("a");b.innerHTML=a;b.normalize&&b.normalize();a=b.firstChild.nodeValue;b.innerHTML="";return a}function ta(a){return a.replace(/&([^;]+);/g,function(b,c){switch(c){case "amp":return"&";case "lt":return"<";case "gt":return">";case "quot":return'"';default:if(c.charAt(0)=="#"){c=Number("0"+c.substr(1));if(!isNaN(c))return String.fromCharCode(c)}return b}})}
function y(a,b){return a.indexOf(b)!=-1}
function ua(a,b){var c=0;a=ja(String(a)).split(".");b=ja(String(b)).split(".");for(var d=Math.max(a.length,b.length),e=0;c==0&&e<d;e++){var f=a[e]||"",i=b[e]||"",h=new RegExp("(\\d*)(\\D*)","g"),m=new RegExp("(\\d*)(\\D*)","g");do{var j=h.exec(f)||["","",""],p=m.exec(i)||["","",""];if(j[0].length==0&&p[0].length==0)break;c=j[1].length==0?0:parseInt(j[1],10);var q=p[1].length==0?0:parseInt(p[1],10);c=z(c,q)||z(j[2].length==0,p[2].length==0)||z(j[2],p[2])}while(c==0)}return c}
function z(a,b){if(a<b)return-1;else if(a>b)return 1;return 0}(Date.now||function(){return(new Date).getTime()})();"StopIteration"in o||Error("StopIteration");function va(a,b,c){for(var d in a)b.call(c,a[d],d,a)}function A(){}A.prototype.P=l;A.prototype.B=function(){if(!this.P){this.P=g;this.r()}};A.prototype.r=function(){};function B(a,b){A.call(this);this.V=b;this.l=[];this.ba(a)}w(B,A);n=B.prototype;n.G=k;n.H=k;n.A=function(a){this.G=a};n.Y=function(a){this.H=a};
n.S=function(){if(this.l.length)return this.l.pop();return this.N()};n.u=function(a){this.l.length<this.V?this.l.push(a):this.O(a)};n.ba=function(a){if(a>this.V)throw Error("[goog.structs.SimplePool] Initial cannot be greater than max");for(var b=0;b<a;b++)this.l.push(this.N())};n.N=function(){return this.G?this.G():{}};n.O=function(a){if(this.H)this.H(a);else if(s(a.B))a.B();else for(var b in a)delete a[b]};n.r=function(){B.Z.r.call(this);for(var a=this.l;a.length;)this.O(a.pop());delete this.l};
var C,D,E,wa,F,xa,ya,za,Aa,Ba;function Ca(){return o.navigator?o.navigator.userAgent:k}function G(){return o.navigator}(function(){xa=F=wa=E=D=C=l;var a;if(a=Ca()){var b=G();C=a.indexOf("Opera")==0;D=!C&&a.indexOf("MSIE")!=-1;wa=(E=!C&&a.indexOf("WebKit")!=-1)&&a.indexOf("Mobile")!=-1;xa=(F=!C&&!E&&b.product=="Gecko")&&b.vendor=="Camino"}})();var Da=C,H=D,Ea=F,I=E,J=function(){var a=G();return a&&a.platform||""}();
(function(){ya=y(J,"Mac");za=y(J,"Win");Aa=y(J,"Linux");Ba=!!G()&&y(G().appVersion||"","X11")})();var Fa=function(){var a="",b;if(Da&&o.opera){a=o.opera.version;a=typeof a=="function"?a():a}else{if(Ea)b=/rv\:([^\);]+)(\)|;)/;else if(H)b=/MSIE\s+([^\);]+)(\)|;)/;else if(I)b=/WebKit\/(\S+)/;if(b)a=(a=b.exec(Ca()))?a[1]:""}return a}(),Ga={};function K(a,b){this.type=a;this.currentTarget=this.target=b}w(K,A);K.prototype.r=function(){delete this.type;delete this.target;delete this.currentTarget};
K.prototype.L=l;K.prototype.qa=g;function L(a,b){a&&this.I(a,b)}w(L,K);n=L.prototype;n.type=k;n.target=k;n.relatedTarget=k;n.offsetX=0;n.offsetY=0;n.clientX=0;n.clientY=0;n.screenX=0;n.screenY=0;n.button=0;n.keyCode=0;n.charCode=0;n.ctrlKey=l;n.altKey=l;n.shiftKey=l;n.metaKey=l;n.Q=k;
n.I=function(a,b){this.type=a.type;this.target=a.target||a.srcElement;this.currentTarget=b;this.relatedTarget=a.relatedTarget?a.relatedTarget:this.type=="mouseover"?a.fromElement:this.type=="mouseout"?a.toElement:k;this.offsetX=typeof a.layerX=="number"?a.layerX:a.offsetX;this.offsetY=typeof a.layerY=="number"?a.layerY:a.offsetY;this.clientX=typeof a.clientX=="number"?a.clientX:a.pageX;this.clientY=typeof a.clientY=="number"?a.clientY:a.pageY;this.screenX=a.screenX||0;this.screenY=a.screenY||0;this.button=
a.button;this.keyCode=a.keyCode||0;this.charCode=a.charCode||(this.type=="keypress"?a.keyCode:0);this.ctrlKey=a.ctrlKey;this.altKey=a.altKey;this.shiftKey=a.shiftKey;this.metaKey=a.metaKey;this.Q=a;delete this.qa;delete this.L};n.r=function(){L.Z.r.call(this);this.Q=k};function Ha(){}var Ia=0;n=Ha.prototype;n.J=k;n.C=k;n.W=k;n.src=k;n.type=k;n.capture=k;n.T=k;n.key=0;n.z=l;n.M=l;
n.I=function(a,b,c,d,e,f){if(s(a))this.J=g;else if(a&&a.handleEvent&&s(a.handleEvent))this.J=l;else throw Error("Invalid listener argument");this.C=a;this.W=b;this.src=c;this.type=d;this.capture=!!e;this.T=f;this.M=l;this.key=++Ia;this.z=l};n.handleEvent=function(a){if(this.J)return this.C.call(this.T||this.src,a);return this.C.handleEvent.call(this.C,a)};var M={},N={},O={},P=new B(0,600);P.A(function(){return{k:0,w:0}});P.Y(function(a){a.k=0});var Q=new B(0,600);Q.A(function(){return[]});
Q.Y(function(a){a.length=0;delete a.v;delete a.K});(new B(0,600)).A(function(){function a(b){return Ja.call(a.src,a.key,b)}return a});function Ka(){return new Ha}var La=new B(0,600);La.A(Ka);function Ma(){return new L}var Na=function(){var a=k;if(H){a=new B(0,600);a.A(Ma)}return a}(),R={};
function Oa(a){if(!M[a])return l;var b=M[a];if(b.z)return l;var c=b.src,d=b.type,e=b.W,f=b.capture;if(c.removeEventListener){if(c==o||!c.ua)c.removeEventListener(d,e,f)}else c.detachEvent&&c.detachEvent(Pa(d),e);c=u(c);e=N[d][f][c];if(O[c]){var i=O[c],h=ea(i,b);h!=-1&&Array.prototype.splice.call(i,h,1).length==1;i.length==0&&delete O[c]}b.z=g;e.K=g;Qa(d,f,c,e);delete M[a];return g}
function Qa(a,b,c,d){if(!d.v)if(d.K){for(var e=0,f=0;e<d.length;e++)if(d[e].z)La.u(d[e]);else{if(e!=f)d[f]=d[e];f++}d.length=f;d.K=l;if(f==0){Q.u(d);delete N[a][b][c];N[a][b].k--;if(N[a][b].k==0){P.u(N[a][b]);delete N[a][b];N[a].k--}if(N[a].k==0){P.u(N[a]);delete N[a]}}}}function Pa(a){if(a in R)return R[a];return R[a]="on"+a}
function Ra(a,b,c,d,e){var f=1;b=u(b);if(a[b]){a.w--;a=a[b];if(a.v)a.v++;else a.v=1;try{for(var i=a.length,h=0;h<i;h++){var m=a[h];if(m&&!m.z)f&=S(m,e)!==l}}finally{a.v--;Qa(c,d,b,a)}}return Boolean(f)}function S(a,b){b=a.handleEvent(b);a.M&&Oa(a.key);return b}
function Ja(a,b){if(!M[a])return g;a=M[a];var c=a.type,d=N;if(!(c in d))return g;d=d[c];var e,f;if(H){e=b||aa("window.event");b=g in d;var i=l in d;if(b){if(e.keyCode<0||e.returnValue!=undefined)return g;a:{var h=l;if(e.keyCode==0)try{e.keyCode=-1;break a}catch(m){h=g}if(h||e.returnValue==undefined)e.returnValue=g}}h=Na.S();h.I(e,this);e=g;try{if(b){for(var j=Q.S(),p=h.currentTarget;p;p=p.parentNode)j.push(p);f=d[g];f.w=f.k;for(var q=j.length-1;!h.L&&q>=0&&f.w;q--){h.currentTarget=j[q];e&=Ra(f,j[q],
c,g,h)}if(i){f=d[l];f.w=f.k;for(q=0;!h.L&&q<j.length&&f.w;q++){h.currentTarget=j[q];e&=Ra(f,j[q],c,l,h)}}}else e=S(a,h)}finally{if(j){j.length=0;Q.u(j)}h.B();Na.u(h)}return e}f=new L(b,this);try{e=S(a,f)}finally{f.B()}return e}function Sa(a){if(a[1]){var b=a[0].indexOf("?");if(b<0)a[1]="?";else if(b==a[0].length-1)a[1]=""}return a.join("")}var Ta=/#|$/;
function Ua(a,b){var c=a.search(Ta),d;a:{d=0;for(var e=b.length;(d=a.indexOf(b,d))>=0&&d<c;){var f=a.charCodeAt(d-1);if(f==38||f==63){f=a.charCodeAt(d+e);if(!f||f==61||f==38||f==35){d=d;break a}}d+=e+1}d=-1}if(d<0)return k;else{e=a.indexOf("&",d);if(e<0||e>c)e=c;d+=b.length+1;a=a.substr(d,e-d);return a=decodeURIComponent(a.replace(/\+/g," "))}}
function Va(a,b){va(b,function(c,d){if(d=="style")a.style.cssText=c;else if(d=="class")a.className=c;else if(d=="for")a.htmlFor=c;else if(d in Wa)a.setAttribute(Wa[d],c);else a[d]=c})}var Wa={cellpadding:"cellPadding",cellspacing:"cellSpacing",colspan:"colSpan",rowspan:"rowSpan",valign:"vAlign",height:"height",width:"width",usemap:"useMap",frameborder:"frameBorder",type:"type"};
function Xa(a,b){var c=b[0],d=b[1];if(H&&d&&(d.name||d.type)){c=["<",c];d.name&&c.push(' name="',x(d.name),'"');if(d.type){c.push(' type="',x(d.type),'"');d=da(d);delete d.type}c.push(">");c=c.join("")}var e=a.createElement(c);if(d)if(typeof d=="string")e.className=d;else Va(e,d);if(b.length>2){function f(i){if(i)e.appendChild(typeof i=="string"?a.createTextNode(i):i)}for(d=2;d<b.length;d++){c=b[d];ba(c)&&!(t(c)&&c.nodeType>0)?fa(Ya(c)?ha(c):c,f):f(c)}}return e}
function T(){return Xa(document,arguments)}I&&(Ga["522"]||(Ga["522"]=ua(Fa,"522")>=0));function Ya(a){if(a&&typeof a.length=="number")if(t(a))return typeof a.item=="function"||typeof a.item=="string";else if(s(a))return typeof a.item=="function";return l}var Za,$a;(function(){$a=(Za="ScriptEngine"in o&&o.ScriptEngine()=="JScript")?o.ScriptEngineMajorVersion()+"."+o.ScriptEngineMinorVersion()+"."+o.ScriptEngineBuildVersion():"0"})();var U=Za;
function V(a){this.d=U?[]:"";a!=k&&this.append.apply(this,arguments)}if(U){V.prototype.F=0;V.prototype.append=function(a,b){if(b==k)this.d[this.F++]=a;else{this.d.push.apply(this.d,arguments);this.F=this.d.length}return this}}else V.prototype.append=function(a,b){this.d+=a;if(b!=k)for(var c=1;c<arguments.length;c++)this.d+=arguments[c];return this};V.prototype.clear=function(){if(U)this.F=this.d.length=0;else this.d=""};
V.prototype.toString=function(){if(U){var a=this.d.join("");this.clear();a&&this.append(a);return a}else return this.d};
function W(a,b,c){a:{a=a||document;c=c&&c!="*"?c.toLowerCase():"";if(a.querySelectorAll&&(c||b)&&(!I||1))b=a.querySelectorAll(c+(b?"."+b:""));else{if(b&&a.getElementsByClassName){a=a.getElementsByClassName(b);if(c){for(var d={},e=0,f=0,i;i=a[f];f++)if(c==i.nodeName.toLowerCase())d[e++]=i;d.length=e;b=d;break a}else{b=a;break a}}a=a.getElementsByTagName(c||"*");if(b){d={};for(f=e=0;i=a[f];f++){c=i.className;if(typeof c.split=="function"&&ga(c.split(" "),b))d[e++]=i}d.length=e;b=d}else b=a}}if(b.length>=
1)return b[0];else throw Error();}function X(a){return document.createTextNode(a)}function ab(a,b){if(b instanceof Array){for(var c=0;c<b.length;c++)a=a.replace("%"+(c+1),b[c]);return a}else return a.replace("%1",b)}var bb=new RegExp("<(/s*(blockquote|body|center|dd|dir|div|dl|dt|form|h1|h2|h3|h4|h5|h6|head|html|hr|isindex|li|menu|noframes|ol|p|table|td|th|tr|title|ul)[^>]*|s*br[^>]*)>","gi"),cb=/<[^>]*>/gi,db=/</g,eb=/>/g;
function fb(a,b){if(!a)return"";if(b)a=a.replace(bb," ");a=a.replace(cb,"");return a.replace(db,"&lt;").replace(eb,"&gt;")}function gb(a,b){if(a.length<=b)return a;var c=a.split(/\s+/);a=[];for(var d=0,e=0;e<c.length&&d<=b;e++){a.push(c[e]);d+=c[e].length+(e?1:0)}a=a.join(" ");if(e!=c.length)a+="...";return a}var Y={};function hb(a){a in Y||(Y[a]=Ua(window.location.search,a));return Y[a]}
function ib(a){if(hb("hl"))a=Sa([a,"&","hl","=",la("en")]);var b=hb("gl");if(b)a=Sa([a,"&","gl","=",la(b)]);return a}
var Z={},jb={blue:{j:"#fff",i:"#bccceb",p:"#090992",o:"#bccceb",m:"#1010c8",g:"#7a7ee0",h:"#e5ecf9",f:"#898de9"},green:{j:"#fff",i:"#d8dbbc",p:"#2d8509",o:"#d8dbbc",m:"#58bf2f",g:"#97e07a",h:"#f5fbeb",f:"#adb094"},slate:{j:"#123",i:"#345",p:"#5e805e",o:"#5e6f80",m:"#abc",g:"#5e6f80",h:"#152939",f:"#abc"},gray:{j:"#fff",i:"#ccc",p:"#666",o:"#ccc",m:"#999",g:"#ccc",h:"#eee",f:"#aaa"},khaki:{j:"#f2e9ca",i:"#8e7c6a",p:"#d52",o:"#cba",m:"#543",g:"#ba9",h:"#eae0c6",f:"#987"},pink:{j:"#fff",i:"#aaa",p:"#d69",
o:"#ddd",m:"#e684ad",g:"#ebc",h:"#fcf0f7",f:"#a88"},black:{j:"#000",i:"#aaa",p:"#ccc",o:"#d8dbbc",m:"#d52",g:"#7a2b0e",h:"#111",f:"#999"}},kb={margin:0,padding:0,background:"transparent none",border:"none",textAlign:"left",textIndent:"0",textDecoration:"none",fontWeight:"normal"};
function $(a,b){this.D="readerpublishermodule"+this.fa();this.e=a;this.X=Z.c;this.$=Z.t;this.ta=Z.s=="true";this.U=Z.b=="true";this.sa=Z.n=="true";if(b){b.innerHTML="";b.id=this.D;this.R(document.getElementById(this.D))}else{document.write('<div id="'+this.D+'" class="reader-publisher-module"></div>');var c=this;window.setTimeout(function(){c.R(document.getElementById(c.D))},0)}}$.prototype.fa=function(){"GRC_c"in window||(window.GRC_c=0);return window.GRC_c++};function lb(a){Z=a}
$.prototype.R=function(a){function b(q){return q}var c=this.ga();this.a(c.pa,a);if(this.$){var d=T("h3");this.a(c.oa,d);d.appendChild(X(this.$));a.appendChild(d)}d=T("ul");this.a(c.na,d);for(var e=0,f;f=this.e.items[e];e++)if(f.alternate){var i=T("li");this.a(c.ma,i);var h=T("a",{href:b(f.alternate.href),title:f.title,"class":"i"});this.a(c.ja,h);var m=fb(f.title||f.content);ia(m==k?"":String(m))||(m=gb(m,48));h.appendChild(X(m));i.appendChild(h);if(this.ta&&!this.U&&f.origin.title){var j=f.origin;
h=T("div",{"class":"s"});this.a(c.la,h);i.appendChild(h);m=j.title;if(m.length>48)m=m.substring(0,48);h.innerHTML=ab("from <a>%1</a>",m);if(j.htmlUrl){j=T("a",{href:b(j.htmlUrl)});j.innerHTML=m;this.a(c.ka,j);h.replaceChild(j,h.getElementsByTagName("a")[0])}}if(this.sa&&!this.U){h="";f=f.annotations||[];for(m=0;j=f[m];m++)if(y(this.e.id,j.userId)&&j.content.length>0){h=j.content;break}if(h.length>0){f=T("div");this.a(c.ia,f);if(h.length>48)h=h.substring(0,48);f.innerHTML='"'+h+'"';i.appendChild(f)}}d.appendChild(i)}a.appendChild(d);
d=T("div",{"class":"f"});this.a(c.ea,d);if(this.e.id){e=this.e.id.search(/^user\/(\d+)\/bundle\//)!=-1;i=this.e.id.indexOf("feed/")==0;f=this.e.alternate&&this.e.alternate.href;if(!i||e||f){f=T("a");this.a(c.f,f);f.appendChild(X(ra("View all &raquo;")));if(e){var p=ib("http://www.google.com/reader/bundle/"+this.e.id);e=mb({ha:p,ra:"Preview &raquo;"});d.appendChild(e);this.a(c.da,W(e,"gr-bundle-table"));this.a(c.ca,W(e,"gr-show-all"));W(e,"gr-subscribe-button").onclick=function(){window.location.href=
p}}else{f.href=i?this.e.alternate.href:ib("http://www.google.com/reader/shared/"+this.e.id);d.appendChild(f)}}}a.appendChild(d)};
$.prototype.ga=function(){if(this.X=="-")return{};var a=jb[this.X];return{pa:{fontFamily:"arial, sans-serif",fontSize:"10pt",background:a.j,border:"solid 1px "+a.i,margin:"0.5em"},oa:{padding:"0.2em 0.5em",background:a.h,borderBottom:"solid 1px "+a.o,color:a.p},na:{padding:"0.2em",margin:"0 0.5em",overflow:"hidden"},ma:{listStyleType:"none",padding:"0.4em 0 0.4em 0"},ja:{color:a.m,borderBottom:"solid 1px "+a.g},la:{color:a.g},ka:{color:a.g},ia:{color:"#777",fontStyle:"italic"},ea:{textAlign:"right",
borderTop:"solid 1px "+a.i,background:a.h,padding:"0.2em 8px",fontSize:"small",whiteSpace:"nowrap"},f:{color:a.f,textDecoration:"underline"},da:{width:"100%"},ca:{textAlign:"right"}}};$.prototype.a=function(a,b){if(a){for(var c in kb)b.style[c]=kb[c];for(var d in a)b.style[d]=a[d]}};window.GRC_p=lb;window.GRC=$;function mb(a,b){var c=b||new V;c.append('<div><table class="gr-bundle-table"><tr><td><input class="gr-subscribe-button" type="button" value="',"Subscribe",'"></td><td class="gr-show-all"><a href="',x(String(a.ha)),'">',a.ra,"</a></td></tr></table></div>");if(!b){b=c.toString();{a=document.createElement("div");a.innerHTML=b;if(a.childNodes.length==1)a=a.firstChild;else{for(b=document.createDocumentFragment();a.firstChild;)b.appendChild(a.firstChild);a=b}}return a}};})();