function pulsanti(idpulsante)
{
  document.write('<div id="pulsante"><ul>');
  document.write('    <li id="'+(idpulsante=="ubuntu"?"current":"plain")+'"><a href="http://www.ubuntu.com/">Ubuntu</a></li>');
  document.write('    <li id="'+(idpulsante=="ubuntu-br"?"current":"plain")+'"><a href="http://www.ubuntu-br.org">Ubuntu-BR</a></li>');
  document.write('    <li id="'+(idpulsante=="ubuntu-pt"?"current":"plain")+'"><a href="http://www.ubuntu-pt.org">Ubuntu-PT</a></li>');
  document.write('    <li id="'+(idpulsante=="forum"?"current":"plain")+'"><a href="http://ubuntuforum-br.org">Fórum</a></li>');
  document.write('    <li id="'+(idpulsante=="planeta"?"current":"plain")+'"><a href="http://planeta.ubuntu-br.org/">Planeta</a></li>');
  document.write('</ul></div>');
}
