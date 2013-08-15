// funcao
function aberto(){document.getElementById("banner_hospedix").className="aberto";}
function fechado(){document.getElementById("banner_hospedix").className="fechado";}
// banner
document.write('<style>');
document.write('.aberto {position:absolute;width:468;height:60;z-index:1;clip:rect(auto,468,280,auto);}');
document.write('.fechado {position:absolute;width:468;height:60;z-index:1;clip:rect(auto,468,60,auto);}');
document.write('</style>');
document.write('<table width="468" height="60" border="0" cellpadding="0" cellspacing="0"><tr><td valign="top">');
document.write('<div id="banner_hospedix" class="fechado" onMouseOver="javascript:aberto()" onMouseOut="javascript:fechado()">');
document.write('<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" width="468" height="280">');
document.write('<param name="movie" value="http://www.hospedix.com.br/banner/ban_exp_hospedix_468x60.swf">');
document.write('<param name="quality" value="high">');
document.write('<param name="wmode" value="transparent">');
document.write('<embed src="http://www.hospedix.com.br/banner/ban_exp_hospedix_468x60.swf" wmode="transparent" quality="high" pluginspage="http://www.macromedia.com/go/getflashplayer" type="application/x-shockwave-flash" width="468" height="280"></embed>');
document.write('</object>');
document.write('</div>');
document.write('</td></tr></table>');