 /************************************
  * Posicao 0 - proteccao de páginas *
  ************************************/
  
 /*****************************************************************************
  * Descrição: Adiciona automaticamente a predefinição {protegido} e {protegido-ip}
  * para artigos protegidos
  * Autor: [[:pt:User:Rei-artur]]
  *****************************************************************************/
 
 addOnloadHook(function(){
 
   if( wgRestrictionEdit == "autoconfirmed" || wgRestrictionEdit == "sysop" ) {
 
     //para evitar as sobposições
     appendCSS('#destaques1 {right: 40px;}');
     appendCSS('#FIST1 {right: 40px;}');
     appendCSS('#atalho {right: 50px;}');
 
     if ( wgPageName == "Página_principal" ) {
 
     } else if (wgAction == "view" && wgRestrictionEdit == "sysop" ) {
 
       document.writeln('<div id="protegida" class="noprint"><a href="/wiki/Wikipedia:P%C3%A1gina_protegida" title="Esta página encontra-se protegida"><img alt="Esta página encontra-se protegida" src="http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Crystal_Clear_action_lock.png/25px-Crystal_Clear_action_lock.png" width="25" height="25" border="0" /></a></div>');

     } else if (wgAction == "view" && wgRestrictionEdit == "autoconfirmed" ) {
 
       document.writeln('<div id="protegida" class="noprint"><a href="/wiki/Wikipedia:P%C3%A1gina_protegida" title="Esta página encontra-se protegida apenas para usuários não-cadastrados"><img alt="Esta página encontra-se protegida apenas para não-cadastrados" src="http://upload.wikimedia.org/wikipedia/commons/thumb/6/64/Crystal_Clear_action_lock3.png/25px-Crystal_Clear_action_lock3.png" width="25" height="25" border="0" /></a></div>');
 
     }
   }
 
 });