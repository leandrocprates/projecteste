//HEADER TAGS PUBLICIDADE - OPEC - NÃO ALTERAR
function OAS_VARS(OAS_page) {
OAS_sitepage = 'www.guiadohardware.com.br/' + OAS_page;


if (OAS_page == 'internas'){
OAS_VARSpos('x15,Top');
}else if(OAS_page == 'noticias'){
OAS_VARSpos('x15,Top2,Top,x09');
}else{
OAS_VARSpos('x15,Top2,x07');
}
}
function OAS_VARSpos(OAS_pos) {
OAS_listpos =  OAS_pos;}
OAS_url = 'http://adserver.ig.com.br/RealMedia/ads/';
OAS_query = '';
OAS_target = '_blank';
OAS_version = 10;
OAS_rn = '001234567890'; OAS_rns = '1234567890';
OAS_rn = new String(Math.random()); OAS_rns = OAS_rn.substring(2, 11);
function OAS_NORMAL (pos) {
 document.write('<a href="' + OAS_url + 'click_nx.ads/' + OAS_sitepage + '/1' + OAS_rns + '@' + OAS_listpos + '!' + pos + '?' + OAS_query + '" target="'+ OAS_target + '">');
 document.write('<img src="' + OAS_url + 'adstream_nx.ads/' + OAS_sitepage + '/1' + OAS_rns + '@' + OAS_listpos + '!' + pos + '?' + OAS_query + '" border="0"></a>');}
function OAS_START() {
OAS_version = 11;
if (navigator.userAgent.indexOf('Mozilla/3') != -1 || navigator.userAgent.indexOf('Mozilla/4.0 WebTV') != -1)
 OAS_version = 10;
if (OAS_version >= 11)
 document.write('<SCRIP' + 'T LANGUAGE=JavaScript1.1 SRC="' + OAS_url + 'adstream_mjx.ads/' + OAS_sitepage + '/1' + OAS_rns + '@' + OAS_listpos + '?' + OAS_query + '"><\/SCRIP' + 'T>');}
document.write('');
function OAS_AD(pos){
 if (OAS_version >= 11)
  OAS_RICH(pos);
 else
  OAS_NORMAL(pos);}
//FIM HEADER TAGS DE PUBLICIDADE

