(function(){
var i=true,l=null,m=false,n=(new Date).getTime(),aa=function(a){var b=(new Date).getTime()-n,c="&dtd="+(b<1000?b:"M");return a+c};var o=this,ba=function(a,b,c){var d=a.split("."),e=c||o;!(d[0]in e)&&e.execScript&&e.execScript("var "+d[0]);for(var f;d.length&&(f=d.shift());)if(!d.length&&b!==undefined)e[f]=b;else e=e[f]?e[f]:(e[f]={})},p=function(a){var b=typeof a;if(b=="object")if(a){if(a instanceof Array||!(a instanceof Object)&&Object.prototype.toString.call(a)=="[object Array]"||typeof a.length=="number"&&typeof a.splice!="undefined"&&typeof a.propertyIsEnumerable!="undefined"&&!a.propertyIsEnumerable("splice"))return"array";
if(!(a instanceof Object)&&(Object.prototype.toString.call(a)=="[object Function]"||typeof a.call!="undefined"&&typeof a.propertyIsEnumerable!="undefined"&&!a.propertyIsEnumerable("call")))return"function"}else return"null";else if(b=="function"&&typeof a.call=="undefined")return"object";return b},ca=function(a){var b=p(a);return b=="array"||b=="object"&&typeof a.length=="number"},da=function(a){return typeof a=="string"},ea=function(a){var b=p(a);return b=="object"||b=="array"||b=="function"};
Math.floor(Math.random()*2147483648).toString(36);
var fa=function(a){var b=p(a);if(b=="object"||b=="array"){if(a.clone)return a.clone.call(a);var c=b=="array"?[]:{};for(var d in a)c[d]=fa(a[d]);return c}return a},ga=function(a,b){var c=a.u;if(arguments.length>2){var d=Array.prototype.slice.call(arguments,2);c&&d.unshift.apply(d,c);c=d}b=a.w||b;a=a.v||a;var e,f=b||o;e=c?function(){var h=Array.prototype.slice.call(arguments);h.unshift.apply(h,c);return a.apply(f,h)}:function(){return a.apply(f,arguments)};e.u=c;e.w=b;e.v=a;return e},ha=Date.now||function(){return(new Date).getTime()},
q=function(a,b,c){ba(a,b,c)};function r(a,b){var c=parseFloat(a);return isNaN(c)||c>1||c<0?b:c}function ia(a,b){if(a=="true")return i;if(a=="false")return m;return b}function t(a,b){var c=/^([\w-]+\.)+[\w-]{2,}(\:[0-9]+)?$/;return c.test(a)?a:b};var ja="pagead2.googlesyndication.com",ka="googleads.g.doubleclick.net",la="pubads.g.doubleclick.net",ma="securepubads.g.doubleclick.net",na="partner.googleadservices.com",v=t("pagead2.googlesyndication.com",ja),oa=t("googleads.g.doubleclick.net",ka),pa=t("pagead2.googlesyndication.com",ja);t("pubads.g.doubleclick.net",la);t("partner.googleadservices.com",na);t("securepubads.g.doubleclick.net",ma);function y(a){return typeof encodeURIComponent=="function"?encodeURIComponent(a):escape(a)}function qa(a,b,c){var d=document.createElement("script");d.type="text/javascript";if(b)d.onload=b;if(c)d.id=c;d.src=a;var e=document.getElementsByTagName("head")[0];if(!e)return m;window.setTimeout(function(){e.appendChild(d)},0);return i}function ra(a,b){a.google_image_requests||(a.google_image_requests=[]);var c=new Image;c.src=b;a.google_image_requests.push(c)}
function sa(a){if(a in ta)return ta[a];return ta[a]=navigator.userAgent.toLowerCase().indexOf(a)!=-1}var ta={};
function ua(){if(navigator.plugins&&navigator.mimeTypes.length){var a=navigator.plugins["Shockwave Flash"];if(a&&a.description)return a.description.replace(/([a-zA-Z]|\s)+/,"").replace(/(\s)+r/,".")}else if(navigator.userAgent&&navigator.userAgent.indexOf("Windows CE")>=0){for(var b=3,c=1;c;)try{c=new ActiveXObject("ShockwaveFlash.ShockwaveFlash."+(b+1));b++}catch(d){c=l}return b.toString()}else if(sa("msie")&&!window.opera){c=l;try{c=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.7")}catch(e){b=
0;try{c=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.6");b=6;c.AllowScriptAccess="always"}catch(f){if(b==6)return b.toString()}try{c=new ActiveXObject("ShockwaveFlash.ShockwaveFlash")}catch(h){}}if(c){b=c.GetVariable("$version").split(" ")[1];return b.replace(/,/g,".")}}return"0"}function va(a){var b=a.google_ad_format;if(b)return b.indexOf("_0ads")>0;return a.google_ad_output!="html"&&a.google_num_radlinks>0}function z(a){return!!a&&a.indexOf("_sdo")!=-1}
function Aa(a){return va(a)||z(a.google_ad_format)}function A(a,b){var c=Math.random();if(c<b){var d=Math.floor(c/b*a.length);return a[d]}return""};var Ba={google_ad_channel:"channel",google_ad_host:"host",google_ad_host_channel:"h_ch",google_ad_host_tier_id:"ht_id",google_ad_region:"region",google_ad_section:"region",google_ad_type:"ad_type",google_adtest:"adtest",google_allow_expandable_ads:"ea",google_alternate_ad_url:"alternate_ad_url",google_alternate_color:"alt_color",google_bid:"bid",google_city:"gcs",google_color_bg:"color_bg",google_color_border:"color_border",google_color_line:"color_line",google_color_link:"color_link",google_color_text:"color_text",
google_color_url:"color_url",google_contents:"contents",google_country:"gl",google_cust_age:"cust_age",google_cust_ch:"cust_ch",google_cust_gender:"cust_gender",google_cust_id:"cust_id",google_cust_interests:"cust_interests",google_cust_job:"cust_job",google_cust_l:"cust_l",google_cust_lh:"cust_lh",google_cust_u_url:"cust_u_url",google_disable_video_autoplay:"disable_video_autoplay",google_ed:"ed",google_encoding:"oe",google_feedback:"feedback_link",google_flash_version:"flash",google_font_face:"f",
google_font_size:"fs",google_gl:"gl",google_hints:"hints",google_kw:"kw",google_kw_type:"kw_type",google_language:"hl",google_page_url:"url",google_referrer_url:"ref",google_region:"gr",google_reuse_colors:"reuse_colors",google_safe:"adsafe",google_tag_info:"gut",google_targeting:"targeting",google_ui_features:"ui",google_ui_version:"uiv",google_video_doc_id:"video_doc_id",google_video_product_type:"video_product_type"},Ca={google_ad_format:"format",google_ad_output:"output",google_ad_callback:"callback",
google_ad_height:"h",google_ad_override:"google_ad_override",google_ad_slot:"slotname",google_ad_width:"w",google_analytics_uacct:"ga_wpids",google_correlator:"correlator",google_cpa_choice:"cpa_choice",google_ctr_threshold:"ctr_t",google_image_size:"image_size",google_last_modified_time:"lmt",google_max_num_ads:"num_ads",google_max_radlink_len:"max_radlink_len",google_num_radlinks:"num_radlinks",google_num_radlinks_per_unit:"num_radlinks_per_unit",google_only_ads_with_video:"only_ads_with_video",
google_page_location:"loc",google_rl_dest_url:"rl_dest_url",google_rl_filtering:"rl_filtering",google_rl_mode:"rl_mode",google_rt:"rt",google_skip:"skip"},Da={google_only_pyv_ads:"pyv",google_with_pyv_ads:"withpyv"};function Ea(a){return Ba[a]||Ca[a]||Da[a]||l};var C=document,D=navigator,E=window;
function Fa(){var a=C.cookie,b=Math.round((new Date).getTime()/1000),c=E.google_analytics_domain_name,d=typeof c=="undefined"?Ga("auto"):Ga(c),e=a.indexOf("__utma="+d+".")>-1,f=a.indexOf("__utmb="+d)>-1,h=a.indexOf("__utmc="+d)>-1,k,j={},g=!!E&&!!E.gaGlobal;if(e){k=a.split("__utma="+d+".")[1].split(";")[0].split(".");j.sid=f&&h?k[3]+"":g&&E.gaGlobal.sid?E.gaGlobal.sid:b+"";j.vid=k[0]+"."+k[1];j.from_cookie=i}else{j.sid=g&&E.gaGlobal.sid?E.gaGlobal.sid:b+"";j.vid=g&&E.gaGlobal.vid?E.gaGlobal.vid:(Math.round(Math.random()*
2147483647)^Ha()&2147483647)+"."+b;j.from_cookie=m}j.dh=d;j.hid=g&&E.gaGlobal.hid?E.gaGlobal.hid:Math.round(Math.random()*2147483647);return E.gaGlobal=j}
function Ha(){var a=C.cookie?C.cookie:"",b=E.history.length,c,d,e=[D.appName,D.version,D.language?D.language:D.browserLanguage,D.platform,D.userAgent,D.javaEnabled()?1:0].join("");if(E.screen)e+=E.screen.width+"x"+E.screen.height+E.screen.colorDepth;else if(E.java){d=java.awt.Toolkit.getDefaultToolkit().getScreenSize();e+=d.screen.width+"x"+d.screen.height}e+=a;e+=C.referrer?C.referrer:"";for(c=e.length;b>0;)e+=b--^c++;return Ia(e)}
function Ia(a){var b=1,c=0,d,e;if(!(a==undefined||a=="")){b=0;for(d=a.length-1;d>=0;d--){e=a.charCodeAt(d);b=(b<<6&268435455)+e+(e<<14);c=b&266338304;b=c!=0?b^c>>21:b}}return b}function Ga(a){if(!a||a==""||a=="none")return 1;if("auto"==a){a=C.domain;if("www."==a.substring(0,4))a=a.substring(4,a.length)}return Ia(a.toLowerCase())};var Ja=document,Ka=ia("false",m),La=ia("false",m),Ma=ia("false",m);ia("false",m);var F=window;document.URL&&(document.URL.indexOf("?google_debug")>0||document.URL.indexOf("&google_debug")>0);var Na=function(a){return a.replace(/^[\s\xa0]+|[\s\xa0]+$/g,"")},Ta=function(a,b){if(b)return a.replace(Oa,"&amp;").replace(Pa,"&lt;").replace(Qa,"&gt;").replace(Ra,"&quot;");else{if(!Sa.test(a))return a;if(a.indexOf("&")!=-1)a=a.replace(Oa,"&amp;");if(a.indexOf("<")!=-1)a=a.replace(Pa,"&lt;");if(a.indexOf(">")!=-1)a=a.replace(Qa,"&gt;");if(a.indexOf('"')!=-1)a=a.replace(Ra,"&quot;");return a}},Oa=/&/g,Pa=/</g,Qa=/>/g,Ra=/\"/g,Sa=/[&<>\"]/,Wa=function(a){if(G(a,"&"))return"document"in o&&!G(a,"<")?
Ua(a):Va(a);return a},Ua=function(a){var b=o.document.createElement("a");b.innerHTML=a;b.normalize&&b.normalize();a=b.firstChild.nodeValue;b.innerHTML="";return a},Va=function(a){return a.replace(/&([^;]+);/g,function(b,c){switch(c){case "amp":return"&";case "lt":return"<";case "gt":return">";case "quot":return'"';default:if(c.charAt(0)=="#"){var d=Number("0"+c.substr(1));if(!isNaN(d))return String.fromCharCode(d)}return b}})},Xa=function(a,b){for(var c=b.length,d=0;d<c;d++){var e=c==1?b:b.charAt(d);
if(a.charAt(0)==e&&a.charAt(a.length-1)==e)return a.substring(1,a.length-1)}return a},G=function(a,b){return a.indexOf(b)!=-1},Za=function(a,b){for(var c=0,d=Na(String(a)).split("."),e=Na(String(b)).split("."),f=Math.max(d.length,e.length),h=0;c==0&&h<f;h++){var k=d[h]||"",j=e[h]||"",g=new RegExp("(\\d*)(\\D*)","g"),u=new RegExp("(\\d*)(\\D*)","g");do{var w=g.exec(k)||["","",""],x=u.exec(j)||["","",""];if(w[0].length==0&&x[0].length==0)break;var s=w[1].length==0?0:parseInt(w[1],10),S=x[1].length==
0?0:parseInt(x[1],10);c=Ya(s,S)||Ya(w[2].length==0,x[2].length==0)||Ya(w[2],x[2])}while(c==0)}return c},Ya=function(a,b){if(a<b)return-1;else if(a>b)return 1;return 0};ha();var H=function(a){this.t=a;this.i=[];this.p=this.h=0;this.d=[];this.n=m};H.prototype.s=function(a,b){var c=this.t[b],d=this.i;this.t[b]=function(e){if(e&&e.length>0){var f=e.length>1?e[1].url:l;d.push([a,Wa(e[0].url),f])}c(e)}};H.prototype.r=function(){this.h++};H.prototype.o=function(){if(!this.n){qa("http://"+v+"/pagead/osd.js");this.n=i}};H.prototype.j=function(a){if(this.h>0)for(var b=document.getElementsByTagName("iframe"),c=0;c<b.length;c++)b.item(c).name=="google_ads_frame"&&a(b.item(c),b.item(c).src)};
H.prototype.k=function(a){var b=this.i;if(b.length>0)for(var c=document.getElementsByTagName("a"),d=function(g,u){return g.innerHTML.indexOf(u)>0},e=0;e<c.length;e++)for(var f=0;f<b.length;f++)if(c.item(e).href==b[f][1]){var h=c.item(e).parentNode;if(b[f][2])for(var k=h,j=0;j<4;j++){if(d(k,b[f][2])){h=k;break}k=k.parentNode}a(h,b[f][0]);b.splice(f,1);break}};H.prototype.e=function(a){this.k(a);this.j(a)};H.prototype.a=function(a){this.p=a};H.prototype.g=function(){return this.p};
H.prototype.f=function(){return this.i.length+this.h};H.prototype.b=function(a){this.d=a};H.prototype.q=function(a,b){if(this.d.length>0){for(var c=0;c<this.d.length;c++)if(this.d[c]==a)if(a=="js")this.s(b,"google_ad_request_done");else a=="html"&&this.r();this.o()}};var $a=function(){window.__google_ad_urls||(window.__google_ad_urls=new H(window));return window.__google_ad_urls};q("Goog_AdSense_getAdAdapterInstance",$a);q("Goog_AdSense_OsdAdapter",H);
q("Goog_AdSense_OsdAdapter.prototype.numBlocks",H.prototype.f);q("Goog_AdSense_OsdAdapter.prototype.findBlocks",H.prototype.e);q("Goog_AdSense_OsdAdapter.prototype.getOsdMode",H.prototype.g);function ab(a,b){try{return a.top.document.URL==b.URL}catch(c){}return m}function bb(a,b,c,d){var e=c||a.google_ad_width,f=d||a.google_ad_height;if(ab(a,b))return m;var h=b.documentElement;if(e&&f){var k=1,j=1;if(a.innerHeight){k=a.innerWidth;j=a.innerHeight}else if(h&&h.clientHeight){k=h.clientWidth;j=h.clientHeight}else if(b.body){k=b.body.clientWidth;j=b.body.clientHeight}if(j>2*f||k>2*e)return m}return i}function cb(a,b){for(var c in b)a["google_"+c]=b[c]}
function db(a,b){if(!b)return a.URL;return a.referrer}function eb(a,b){if(!b&&a.google_referrer_url==l)return"0";else if(b&&a.google_referrer_url==l)return"1";else if(!b&&a.google_referrer_url!=l)return"2";else if(b&&a.google_referrer_url!=l)return"3";return"4"}function fb(a,b,c,d){a.page_url=db(c,d);a.page_location=l}function gb(a,b,c,d){a.page_url=b.google_page_url;a.page_location=db(c,d)||"EMPTY"}
function hb(a,b){var c={},d=bb(a,b,a.google_ad_width,a.google_ad_height);c.iframing=eb(a,d);a.google_page_url?gb(c,a,b,d):fb(c,a,b,d);c.last_modified_time=b.URL==c.page_url?Date.parse(b.lastModified)/1000:l;c.referrer_url=d?a.google_referrer_url:a.google_page_url&&a.google_referrer_url?a.google_referrer_url:b.referrer;return c}function ib(a){var b={},c=a.URL.substring(a.URL.lastIndexOf("http"));b.iframing=l;b.page_url=c;b.page_location=a.URL;b.last_modified_time=l;b.referrer_url=c;return b}
function jb(a,b){var c=kb(a,b);cb(a,c)}function kb(a,b){var c;return c=a.google_page_url==l&&lb[b.domain]?ib(b):hb(a,b)}var lb={};lb["ad.yieldmanager.com"]=i;var mb=function(a,b,c){var d=ga(b,o,a),e=window.onerror;window.onerror=d;try{c()}catch(f){var h=f.toString(),k="";if(f.fileName)k=f.fileName;var j=-1;if(f.lineNumber)j=f.lineNumber;var g=d(h,k,j);if(!g)throw f;}window.onerror=e};q("google_protectAndRun",mb);
var ob=function(a,b,c,d){if(Math.random()<0.01){var e=Ja,f=["http://",v,"/pagead/gen_204","?id=jserror","&cb=",Ka?1:0,"&cd=",La?1:0,"&context=",y(a),"&msg=",y(b),"&file=",y(c),"&line=",y(d.toString()),"&url=",y(e.URL.substring(0,512)),"&ref=",y(e.referrer.substring(0,512))];f.push(nb());ra(F,f.join(""))}return!Ma};q("google_handleError",ob);
var nb=function(){var a=["&client=",y(F.google_ad_client),"&format=",y(F.google_ad_format),"&slotname=",y(F.google_ad_slot),"&output=",y(F.google_ad_output),"&ad_type=",y(F.google_ad_type)];return a.join("")};var pb=function(a,b,c){if(a.forEach)a.forEach(b,c);else if(Array.forEach)Array.forEach(a,b,c);else for(var d=a.length,e=da(a)?a.split(""):a,f=0;f<d;f++)f in e&&b.call(c,e[f],f,a)},qb=function(a){if(p(a)=="array")return a.concat();else{for(var b=[],c=0,d=a.length;c<d;c++)b[c]=a[c];return b}};var I=function(a,b){this.x=a!==undefined?a:0;this.y=b!==undefined?b:0};I.prototype.clone=function(){return new I(this.x,this.y)};I.prototype.toString=function(){return"("+this.x+", "+this.y+")"};var J=function(a,b){this.width=a;this.height=b};J.prototype.clone=function(){return new J(this.width,this.height)};J.prototype.toString=function(){return"("+this.width+" x "+this.height+")"};J.prototype.ceil=function(){this.width=Math.ceil(this.width);this.height=Math.ceil(this.height);return this};J.prototype.floor=function(){this.width=Math.floor(this.width);this.height=Math.floor(this.height);return this};
J.prototype.round=function(){this.width=Math.round(this.width);this.height=Math.round(this.height);return this};J.prototype.scale=function(a){this.width*=a;this.height*=a;return this};var rb=function(a,b,c){for(var d in a)b.call(c,a[d],d,a)};var K,tb,yb,zb,Ab,Bb,Cb,Db,Eb,Fb,Gb=function(){return o.navigator?o.navigator.userAgent:l},Hb=function(){return o.navigator},Ib=function(){Bb=Ab=zb=yb=tb=K=m;var a;if(a=Gb()){var b=Hb();K=a.indexOf("Opera")==0;tb=!K&&a.indexOf("MSIE")!=-1;zb=(yb=!K&&a.indexOf("WebKit")!=-1)&&a.indexOf("Mobile")!=-1;Bb=(Ab=!K&&!yb&&b.product=="Gecko")&&b.vendor=="Camino"}};Ib();
var L=K,M=tb,Jb=Ab,N=yb,Kb=zb,Lb=function(){var a=Hb();return a&&a.platform||""},Mb=Lb(),Nb=function(){Cb=G(Mb,"Mac");Db=G(Mb,"Win");Eb=G(Mb,"Linux");Fb=!!Hb()&&G(Hb().appVersion||"","X11")};Nb();
var Ob=Cb,Pb=Db,Qb=Eb,Rb=function(){var a="",b;if(L&&o.opera){var c=o.opera.version;a=typeof c=="function"?c():c}else{if(Jb)b=/rv\:([^\);]+)(\)|;)/;else if(M)b=/MSIE\s+([^\);]+)(\)|;)/;else if(N)b=/WebKit\/(\S+)/;if(b){var d=b.exec(Gb());a=d?d[1]:""}}return a},Sb=Rb(),Tb={},O=function(a){return Tb[a]||(Tb[a]=Za(Sb,a)>=0)};var Ub;var Vb=function(a){return da(a)?document.getElementById(a):a},Wb=Vb,Yb=function(a,b){rb(b,function(c,d){if(d=="style")a.style.cssText=c;else if(d=="class")a.className=c;else if(d=="for")a.htmlFor=c;else if(d in Xb)a.setAttribute(Xb[d],c);else a[d]=c})},Xb={cellpadding:"cellPadding",cellspacing:"cellSpacing",colspan:"colSpan",rowspan:"rowSpan",valign:"vAlign",height:"height",width:"width",usemap:"useMap",frameborder:"frameBorder",type:"type"},Zb=function(a){var b=a.document;if(N&&!O("500")&&!Kb){if(typeof a.innerHeight==
"undefined")a=window;var c=a.innerHeight,d=a.document.documentElement.scrollHeight;if(a==a.top)if(d<c)c-=15;return new J(a.innerWidth,c)}var e=b.compatMode=="CSS1Compat"&&(!L||L&&O("9.50"))?b.documentElement:b.body;return new J(e.clientWidth,e.clientHeight)},$b=function(a){var b=!N&&a.compatMode=="CSS1Compat"?a.documentElement:a.body;return new I(b.scrollLeft,b.scrollTop)},bc=function(){return ac(document,arguments)},ac=function(a,b){var c=b[0],d=b[1];if(M&&d&&(d.name||d.type)){var e=["<",c];d.name&&
e.push(' name="',Ta(d.name),'"');if(d.type){e.push(' type="',Ta(d.type),'"');d=fa(d);delete d.type}e.push(">");c=e.join("")}var f=a.createElement(c);if(d)if(da(d))f.className=d;else Yb(f,d);if(b.length>2){function h(g){if(g)f.appendChild(da(g)?a.createTextNode(g):g)}for(var k=2;k<b.length;k++){var j=b[k];ca(j)&&!(ea(j)&&j.nodeType>0)?pb(cc(j)?qb(j):j,h):h(j)}}return f},dc=function(a,b){a.appendChild(b)},ec=function(a){return a&&a.parentNode?a.parentNode.removeChild(a):l},fc=function(a,b){var c=b.parentNode;
c&&c.replaceChild(a,b)},gc=N&&O("522"),hc=function(a,b){if(typeof a.contains!="undefined"&&!gc&&b.nodeType==1)return a==b||a.contains(b);if(typeof a.compareDocumentPosition!="undefined")return a==b||Boolean(a.compareDocumentPosition(b)&16);for(;b&&a!=b;)b=b.parentNode;return b==a},P=function(a){return a.nodeType==9?a:a.ownerDocument||a.document},cc=function(a){if(a&&typeof a.length=="number")if(ea(a))return typeof a.item=="function"||typeof a.item=="string";else if(p(a)=="function")return typeof a.item==
"function";return m},Q=function(a){this.c=a||o.document||document};Q.prototype.createElement=function(a){return this.c.createElement(a)};Q.prototype.createTextNode=function(a){return this.c.createTextNode(a)};Q.prototype.m=function(){return this.c.compatMode=="CSS1Compat"};Q.prototype.l=function(){return $b(this.c)};Q.prototype.appendChild=dc;Q.prototype.removeNode=ec;Q.prototype.replaceNode=fc;Q.prototype.contains=hc;var ic,jc,kc,lc,mc,nc,oc=function(){nc=mc=lc=kc=jc=ic=m;var a=Gb();if(a)if(a.indexOf("Firefox")!=-1)ic=i;else if(a.indexOf("Camino")!=-1)jc=i;else if(a.indexOf("iPhone")!=-1||a.indexOf("iPod")!=-1)kc=i;else if(a.indexOf("Android")!=-1)lc=i;else if(a.indexOf("Chrome")!=-1)mc=i;else if(a.indexOf("Safari")!=-1)nc=i};oc();var pc=function(a,b){var c=P(a);if(c.defaultView&&c.defaultView.getComputedStyle){var d=c.defaultView.getComputedStyle(a,"");if(d)return d[b]}return l},R=function(a,b){return pc(a,b)||(a.currentStyle?a.currentStyle[b]:l)||a.style[b]},qc=function(a){var b;b=a?a.nodeType==9?a:P(a):document;if(M&&!(b?new Q(P(b)):Ub||(Ub=new Q)).m())return b.body;return b.documentElement},rc=function(a){var b=a.getBoundingClientRect();if(M){var c=a.ownerDocument;b.left-=c.documentElement.clientLeft+c.body.clientLeft;
b.top-=c.documentElement.clientTop+c.body.clientTop}return b},sc=function(a){if(M)return a.offsetParent;for(var b=P(a),c=R(a,"position"),d=c=="fixed"||c=="absolute",e=a.parentNode;e&&e!=b;e=e.parentNode){c=R(e,"position");d=d&&c=="static"&&e!=b.documentElement&&e!=b.body;if(!d&&(e.scrollWidth>e.clientWidth||e.scrollHeight>e.clientHeight||c=="fixed"||c=="absolute"))return e}return l},tc=function(a){var b,c=P(a),d=R(a,"position"),e=Jb&&c.getBoxObjectFor&&!a.getBoundingClientRect&&d=="absolute"&&(b=
c.getBoxObjectFor(a))&&(b.screenX<0||b.screenY<0),f=new I(0,0),h=qc(c);if(a==h)return f;if(a.getBoundingClientRect){b=rc(a);var k=(c?new Q(P(c)):Ub||(Ub=new Q)).l();f.x=b.left+k.x;f.y=b.top+k.y}else if(c.getBoxObjectFor&&!e){b=c.getBoxObjectFor(a);var j=c.getBoxObjectFor(h);f.x=b.screenX-j.screenX;f.y=b.screenY-j.screenY}else{var g=a;do{f.x+=g.offsetLeft;f.y+=g.offsetTop;if(g!=a){f.x+=g.clientLeft||0;f.y+=g.clientTop||0}if(N&&R(g,"position")=="fixed"){f.x+=c.body.scrollLeft;f.y+=c.body.scrollTop;
break}g=g.offsetParent}while(g&&g!=a);if(L||N&&d=="absolute")f.y-=c.body.offsetTop;for(g=a;(g=sc(g))&&g!=c.body&&g!=h;){f.x-=g.scrollLeft;if(!L||g.tagName!="TR")f.y-=g.scrollTop}}return f};Jb&&O("1.9");
var uc=function(a,b,c,d){if(/^\d+px?$/.test(b))return parseInt(b,10);else{var e=a.style[c],f=a.runtimeStyle[c];a.runtimeStyle[c]=a.currentStyle[c];a.style[c]=b;var h=a.style[d];a.style[c]=e;a.runtimeStyle[c]=f;return h}},vc=function(a){var b=P(a),c="";if(b.createTextRange){var d=b.body.createTextRange();d.moveToElementText(a);c=d.queryCommandValue("FontName")}if(!c){c=R(a,"fontFamily");if(L&&Qb)c=c.replace(/ \[[^\]]*\]/,"")}var e=c.split(",");if(e.length>1)c=e[0];return Xa(c,"\"'")},wc=function(a){var b=
a.match(/[^\d]+$/);return b&&b[0]||l},xc={cm:1,"in":1,mm:1,pc:1,pt:1},yc={em:1,ex:1},zc=function(a){var b=R(a,"fontSize"),c=wc(b);if(b&&"px"==c)return parseInt(b,10);if(M)if(c in xc)return uc(a,b,"left","pixelLeft");else if(a.parentNode&&a.parentNode.nodeType==1&&c in yc){var d=a.parentNode,e=R(d,"fontSize");return uc(d,b==e?"1em":b,"left","pixelLeft")}var f=bc("span",{style:"visibility:hidden;position:absolute;line-height:0;padding:0;margin:0;border:0;height:1em;"});dc(a,f);b=f.offsetHeight;ec(f);
return b};var T={};function Ac(a){if(a==1)return i;return!T[a]}function U(a,b){if(a)if(b==1)if(T[b])T[b]+=","+a;else T[b]=a;else T[b]=a}function Bc(){var a=[];for(var b in T)a.push(T[b]);return a.join(",")}function Cc(a,b){if(a&&a instanceof Array)for(var c=0;c<a.length;c++)a[c]&&typeof a[c]=="string"&&U(a[c],b)}var Dc=m;
function Ec(a,b){var c="script";(Dc=Fc(a,b))||(a.google_allow_expandable_ads=m);var d=!Gc();Dc&&d&&b.write("<"+c+' src="http://'+v+'/pagead/expansion_embed.js"></'+c+">");var e=Hc(a,b,r("1",0.01)),f=d||e;f&&sa("msie")&&!window.opera?b.write("<"+c+' src="http://'+v+'/pagead/render_ads.js"></'+c+">"):b.write("<"+c+'>google_protectAndRun("ads_core.google_render_ad", google_handleError, google_render_ad);</'+c+">")}function V(a){return a!=l?'"'+a+'"':'""'}
function W(a,b){if(a&&b)window.google_ad_url+="&"+a+"="+b}function X(a){var b=window,c=Ea(a),d=b[a];W(c,d)}function Y(a,b){b!=l&&W(a,y(b))}function Z(a){var b=window,c=Ea(a),d=b[a];Y(c,d)}function $(a,b){var c=window,d=Ea(a),e=c[a];if(d&&e&&typeof e=="object")e=e[b%e.length];W(d,e)}
function Ic(a){var b=a.screen,c=navigator.javaEnabled(),d=-(new Date).getTimezoneOffset();if(b){W("u_h",b.height);W("u_w",b.width);W("u_ah",b.availHeight);W("u_aw",b.availWidth);W("u_cd",b.colorDepth)}W("u_tz",d);W("u_his",history.length);W("u_java",c);navigator.plugins&&W("u_nplug",navigator.plugins.length);navigator.mimeTypes&&W("u_nmime",navigator.mimeTypes.length)}function Jc(a){if(a){a=a.toLowerCase();if(a.substring(0,3)!="ca-")a="ca-"+a}return a}
function Kc(a){if(a){a=a.toLowerCase();if(a.substring(0,9)!="dist-aff-")a="dist-aff-"+a}return a}function Lc(a){var b="google_unique_id";if(a[b])++a[b];else a[b]=1;return a[b]}function Mc(){var a=M&&O("6"),b=Jb&&O("1.8.1"),c=N&&O("525");if(Pb&&(a||b||c))return i;else if(Ob&&(c||b))return i;else if(Qb&&b)return i;return m}function Gc(){return(typeof ExpandableAdSlotFactory=="function"||typeof ExpandableAdSlotFactory=="object")&&typeof ExpandableAdSlotFactory.createIframe=="function"}
function Fc(a,b){if(a.google_allow_expandable_ads===m||!b.body||a.google_ad_output!="html"||bb(a,b)||Aa(a)||isNaN(a.google_ad_height)||isNaN(a.google_ad_width)||!Mc())return m;return i}function Nc(){var a;if(F.google_ad_output=="html"&&!Aa(F)&&Ac(0)){var b=["6083035","6083034"];a=A(b,r("0",0));U(a,0)}return a=="6083035"}
function Oc(a,b){if((a.google_unique_id||0)==0&&a.google_ad_output=="html"&&document.body&&typeof b.body.getBoundingClientRect=="function")return A(["36812001","36812002"],r("0.01",0));return""}
function Pc(a){var b="";if((a.google_unique_id||0)==0&&(a.google_ad_output=="js"||a.google_ad_output=="html")){Aa(a)||(b=A(["36813001","36813002","36813003","36813004"],r("0.008",0)));if(b=="")b=A(["36813005","36813006"],r("0.008",0))}return b}function Qc(a,b){switch(a){case "36813002":b.a(1);b.b(["js"]);break;case "36813003":b.a(1);b.b(["html"]);break;case "36813004":b.a(2);b.b(["html","js"]);break;case "36813006":b.a(0);b.b(["html","js"]);break}}
function Rc(a){if(a.body)try{return Zb(window)}catch(b){return new J(-12245933,-12245933)}else return new J(-1,-1)}
function Sc(a,b,c,d){var e=Lc(a);c=c.substring(0,1992);c=c.replace(/%\w?$/,"");var f="script";if((a.google_ad_output=="js"||a.google_ad_output=="json_html")&&(a.google_ad_request_done||a.google_radlink_request_done))b.write("<"+f+' language="JavaScript1.1" src='+V(aa(c))+"></"+f+">");else if(a.google_ad_output=="html")if(Dc&&Gc()){var h=a.google_container_id||d||l;a["google_expandable_ad_slot"+e]=ExpandableAdSlotFactory.createIframe("google_ads_frame"+e,aa(c),a.google_ad_width,a.google_ad_height,
h)}else{var k='<iframe name="google_ads_frame" width='+V(a.google_ad_width)+" height="+V(a.google_ad_height)+" frameborder="+V(a.google_ad_frameborder)+" src="+V(aa(c))+' marginwidth="0" marginheight="0" vspace="0" hspace="0" allowtransparency="true" scrolling="no"></iframe>';a.google_container_id?Tc(a.google_container_id,b,k):b.write(k)}}function Uc(a,b,c){if(!a)return m;if(!b)return i;return c}
function Vc(a){for(var b in Ba)a[b]=l;for(b in Ca)b=="google_correlator"||(a[b]=l);for(b in Da)a[b]=l;a.google_allow_expandable_ads=l;a.google_container_id=l;a.google_tag_info=l;a.google_eids=l}
function Wc(a,b){var c=l,d=window,e=document,f=n,h=d.google_ad_format,k=Xc(d),j;if(d.google_cpa_choice!=c){d.google_ad_url=k+"/cpa/ads?";j=escape(Jc(d.google_ad_client));d.google_ad_region="_google_cpa_region_";X("google_cpa_choice");if(typeof e.characterSet!="undefined")Y("oe",e.characterSet);else typeof e.charset!="undefined"&&Y("oe",e.charset)}else if(z(h)){d.google_ad_url=k+"/pagead/sdo?";j=escape(Kc(d.google_ad_client))}else{d.google_ad_url=Nc()?k+"/pagead/render_iframe_ads.html#":k+"/pagead/ads?";
j=escape(Jc(d.google_ad_client))}d.google_ad_url+="client="+j;X("google_ad_host");X("google_ad_host_tier_id");var g=d.google_num_slots_by_client,u=d.google_num_slots_by_channel,w=d.google_prev_ad_formats_by_region,x=d.google_prev_ad_slotnames_by_region;if(d.google_ad_region==c&&d.google_ad_section!=c)d.google_ad_region=d.google_ad_section;var s=d.google_ad_region==c?"":d.google_ad_region;if(z(h)){d.google_num_sdo_slots=d.google_num_sdo_slots?d.google_num_sdo_slots+1:1;if(d.google_num_sdo_slots>4)return m}else if(va(d)){d.google_num_0ad_slots=
d.google_num_0ad_slots?d.google_num_0ad_slots+1:1;if(d.google_num_0ad_slots>3)return m}else if(d.google_cpa_choice==c){d.google_num_ad_slots=d.google_num_ad_slots?d.google_num_ad_slots+1:1;if(d.google_num_slots_to_rotate){w[s]=c;x[s]=c;if(d.google_num_slot_to_show==c)d.google_num_slot_to_show=f%d.google_num_slots_to_rotate+1;if(d.google_num_slot_to_show!=d.google_num_ad_slots)return m}else if(d.google_num_ad_slots>6&&s=="")return m}W("dt",n);X("google_language");d.google_country?X("google_country"):
X("google_gl");X("google_region");Z("google_city");Z("google_hints");X("google_safe");X("google_encoding");X("google_last_modified_time");Z("google_alternate_ad_url");X("google_alternate_color");X("google_skip");X("google_targeting");var S=d.google_ad_client;if(g[S])g[S]+=1;else{g[S]=1;g.length+=1}if(w[s])if(!z(h)){Y("prev_fmts",w[s].toLowerCase());g.length>1&&W("slot",g[S])}x[s]&&Y("prev_slotnames",x[s].toLowerCase());if(Uc(h,d.google_ad_slot,d.google_override_format)){Y("format",h.toLowerCase());
z(h)||(w[s]=w[s]?w[s]+","+h:h)}else if(d.google_ad_slot)x[s]=x[s]?x[s]+","+d.google_ad_slot:d.google_ad_slot;X("google_max_num_ads");W("output",d.google_ad_output);X("google_adtest");X("google_ad_callback");X("google_ad_slot");Z("google_correlator");d.google_new_domain_checked==1&&d.google_new_domain_enabled==0&&W("dblk",1);if(d.google_ad_channel){Z("google_ad_channel");for(var sb="",ub=d.google_ad_channel.split(Yc),wa=0;wa<ub.length;wa++){var xa=ub[wa];if(u[xa])sb+=xa+"+";else u[xa]=1}Y("pv_ch",
sb)}if(d.google_ad_host_channel){Z("google_ad_host_channel");var dd=Zc(d.google_ad_host_channel,d.google_viewed_host_channels);Y("pv_h_ch",dd)}Z("google_page_url");$("google_color_bg",f);$("google_color_text",f);$("google_color_link",f);$("google_color_url",f);$("google_color_border",f);$("google_color_line",f);d.google_reuse_colors?W("reuse_colors",1):W("reuse_colors",0);X("google_font_face");X("google_font_size");X("google_kw_type");Z("google_kw");Z("google_contents");X("google_num_radlinks");X("google_max_radlink_len");
X("google_rl_filtering");X("google_rl_mode");X("google_rt");Z("google_rl_dest_url");X("google_num_radlinks_per_unit");X("google_ad_type");X("google_image_size");X("google_ad_region");Cc(d.google_eids,1);var ya;if(Ac(0)){ya=A(["36814001","36814002"],r("0",0));U(ya,0)}Y("eid",Bc());var vb=d.google_allow_expandable_ads;if(vb!=l)vb?W("ea","1"):W("ea","0");Ka&&W("cb",1);La&&W("cd",1);X("google_feedback");Z("google_referrer_url");Z("google_page_location");W("frm",d.google_iframing);
X("google_bid");X("google_ctr_threshold");X("google_cust_age");X("google_cust_gender");X("google_cust_interests");X("google_cust_id");X("google_cust_job");X("google_cust_u_url");X("google_cust_l");X("google_cust_lh");X("google_cust_ch");X("google_ed");X("google_video_doc_id");X("google_video_product_type");Z("google_ui_features");Z("google_ui_version");Z("google_tag_info");Z("google_only_ads_with_video");Z("google_only_pyv_ads");Z("google_with_pyv_ads");Z("google_disable_video_autoplay");var wb=m;
if(a){Y("dff",vc(a));Y("dfs",zc(a));var B;if(b)if(typeof a.getBoundingClientRect=="function"){var xb=a.getBoundingClientRect();B={x:xb.left,y:xb.top}}else{B={};B.x="-252738";B.y="-252738"}else try{B=tc(a)}catch(sd){B={};B.x="-252738";B.y="-252738"}if(B){wb=i;Y("adx",B.x);Y("ady",B.y)}}if(wb||ya=="36814002"){var za=Rc(e);if(za){Y("biw",za.width);Y("bih",za.height)}}Fa();W("ga_vid",d.gaGlobal.vid);W("ga_sid",d.gaGlobal.sid);W("ga_hid",d.gaGlobal.hid);W("ga_fc",d.gaGlobal.from_cookie);Z("google_analytics_uacct");
X("google_ad_override");X("google_flash_version");W("w",d.google_ad_width||-1);W("h",d.google_ad_height||-1);Ic(d);return i}function Zc(a,b){for(var c=a.split("|"),d=-1,e=[],f=0;f<c.length;f++){var h=c[f].split(Yc);b[f]||(b[f]={});for(var k="",j=0;j<h.length;j++){var g=h[j];if(!(g==""))if(b[f][g])k+="+"+g;else b[f][g]=1}k=k.slice(1);e[f]=k;if(k!="")d=f}var u="";if(d>-1){for(f=0;f<d;f++)u+=e[f]+"|";u+=e[d]}return u}
function $c(){var a=window,b=document,c=$a(),d=a.google_enable_osd,e="";if(d===i){e="36813006";Qc(e,c)}else if(d!==m&&Ac(0)){e=A(["68120011","68120021","68120031","68120041"],r("0",0));if(e==""){e=Oc(a,b);if(e==""){e=Pc(a);e!=""&&Qc(e,c)}}}U(e,0);var f,h=m,k=m,j=m;switch(e){case "68120031":j=i;case "68120021":k=i;case "68120041":h=i;break;case "36812002":if(!window.google_atf_included){window.google_atf_included=i;qa("http://"+v+"/pagead/atf.js")}break}if(h){var g="google_temp_span";
f=a.google_container_id&&Wb(a.google_container_id)||Wb(g);if(!f&&!a.google_container_id){b.write("<span id="+g+"></span>");f=Wb(g)}}var u=m;u=k?Wc(f,j):Wc();f&&f.id==g&&ec(f);if(u){c.q(a.google_ad_output,a.google_ad_url);Sc(a,b,a.google_ad_url);Vc(a)}}function ad(a,b,c,d){var e=ob(a,b,c,d);Ec(window,document);return e}
function bd(){var a=window,b=l;if(a.google_ad_frameborder==b)a.google_ad_frameborder=0;if(a.google_ad_output==b)a.google_ad_output="html";if(z(a.google_ad_format)){var c=a.google_ad_format.match(/^(\d+)x(\d+)_.*/);if(c){a.google_ad_width=parseInt(c[1],10);a.google_ad_height=parseInt(c[2],10);a.google_ad_output="html"}}if(a.google_ad_format==b&&a.google_ad_output=="html")a.google_ad_format=a.google_ad_width+"x"+a.google_ad_height;jb(a,document);if(a.google_num_slots_by_channel==b)a.google_num_slots_by_channel=
[];if(a.google_viewed_host_channels==b)a.google_viewed_host_channels=[];if(a.google_num_slots_by_client==b)a.google_num_slots_by_client=[];if(a.google_prev_ad_formats_by_region==b)a.google_prev_ad_formats_by_region=[];if(a.google_prev_ad_slotnames_by_region==b)a.google_prev_ad_slotnames_by_region=[];if(a.google_correlator==b)a.google_correlator=n;if(a.google_adslot_loaded==b)a.google_adslot_loaded={};if(a.google_adContentsBySlot==b)a.google_adContentsBySlot={};if(a.google_flash_version==b)a.google_flash_version=
ua();if(a.google_new_domain_checked==b)a.google_new_domain_checked=0;if(a.google_new_domain_enabled==b)a.google_new_domain_enabled=0}function cd(a){for(var b={},c=a.split("?"),d=c[c.length-1].split("&"),e=0;e<d.length;e++){var f=d[e].split("=");if(f[0])try{b[f[0].toLowerCase()]=f.length>1?window.decodeURIComponent?decodeURIComponent(f[1].replace(/\+/g," ")):unescape(f[1]):""}catch(h){}}return b}
function ed(){var a=window,b=cd(document.URL);if(b.google_ad_override){a.google_ad_override=b.google_ad_override;a.google_adtest="on"}}function Tc(a,b,c){if(a){var d=b.getElementById(a);if(d&&c&&c.length!=""){d.style.visibility="visible";d.innerHTML=c}}}var Yc=/[+, ]/;window.google_render_ad=$c;var fd={google:1,googlegroups:1,gmail:1,googlemail:1,googleimages:1,googleprint:1};function gd(a){var b=a.google_page_location||a.google_page_url;if(!b)return m;b=b.toString();if(b.indexOf("http://")==0)b=b.substring(7,b.length);else if(b.indexOf("https://")==0)b=b.substring(8,b.length);var c=b.indexOf("/");if(c==-1)c=b.length;var d=b.substring(0,c),e=d.split("."),f=m;if(e.length>=3)f=e[e.length-3]in fd;if(e.length>=2)f=f||e[e.length-2]in fd;return f}
function Hc(a,b,c){if(gd(a)){a.google_new_domain_checked=1;return m}if(a.google_new_domain_checked==0){var d=Math.random();if(d<=c){var e="http://"+oa+"/pagead/test_domain.js",f="script";b.write("<"+f+' src="'+e+'"></'+f+">");a.google_new_domain_checked=1;return i}}return m}function Xc(a){if(!gd(a)&&a.google_new_domain_enabled==1)return"http://"+oa;return"http://"+pa};var hd=["30143070","30143071","30143075"],id=typeof window.postMessage=="function"||typeof window.postMessage=="object"||typeof document.postMessage=="function",kd=function(a,b){a.google_allow_expandable_ads=m;typeof A1_googleCreateSlot=="function"?A1_googleCreateSlot(a.google_ad_client):jd(a,b)},md=function(){if(!ld())return m;return i},nd=function(a){if(Aa(a))return m;var b=a.google_ad_output;if(b&&b!="html")return m;var c=a.google_ad_client;if(typeof c!="string"||c.substring(0,4)!="pub-"&&c.substring(0,
7)!="ca-pub-")return m;return i},pd=function(a){if(typeof a.google_a1_eid=="string")return a.google_a1_eid;var b=r("0.001",0);a.google_a1_eid=od(hd,b);return a.google_a1_eid},jd=function(a,b){if(!a.google_included_a1_script){var c="script",d="/pagead/show_ads_sra3.js?v\x3d1";b.write("<"+c+' src="http://'+v+d+'"></'+c+">");a.google_included_a1_script=i}},ld=function(){if(M&&O("8"))return m;return id||!N},od=function(a,b){var c=Math.random();if(c<b){var d=Math.floor(c/b*a.length);return a[d]}return""};function qd(){ed();mb("show_ads.google_init_globals",ad,bd);Ec(window,document)}function rd(){if(!md(window)||!nd(window))qd();else if(Ma&&window.google_use_a1===i)kd(window,document);else{var a=pd(window);a&&U(a,0);!a||a=="30143070"?qd():kd(window,document)}}mb("show_ads.main",ob,rd);
})()
