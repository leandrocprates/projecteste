/* generated javascript */
var skin = 'monobook';
var stylepath = 'http://bits.wikimedia.org/skins-1.5';

/* MediaWiki:Common.js */
//<source lang="javascript">
/* Todo código JavaScript presente aqui será carregado por todos os usuários em cada página carregada. */

 /** Importar scripts específicos se for necessário ******************************************/

if (wgAction == "edit" || wgAction == "submit") //scripts específicos para editar páginas
{
    importScript("MediaWiki:Common.js/edit.js")
}
else if ( wgCanonicalSpecialPageName == "Search" ||wgPageName == "Special:Search" || wgPageName == "Special:Busca" || wgPageName == "Especial:Search"  || wgPageName == "Especial:Busca" ) //scripts específicos para Especial:Busca
{
    importScript("MediaWiki:Common.js/search.js")
}

if (navigator.appName == "Microsoft Internet Explorer") //scripts específicos para Internet Explorer
{
    importScript("MediaWiki:Common.js/IEFixes.js")
}


 /** Importar módulos JavaScript de páginas da fr.wikipedia.org ******************************
  * Obs: Importar os demais scripts utilizados da página francesa e utilizar o
  * importScript() acima, que opossui a mesma função.
  ********************************************************************************************/
 function loadJs(page)
 {
  document.write('<script type="text/javascript" src="' +
                'http://fr.wikipedia.org/w/index.php?title=' + page +
                '&action=raw&ctype=text/javascript&dontcountme=s"></script>');
 }


 /** Link destaque ***************************************************************************
  *  Descrição: Adiciona estrela ao lado da ligação dos artigos destacados das outras Wikipédias
  ********************************************************************************************/
function LinkFA() 
 {
     if ( document.getElementById( "p-lang" ) ) {
         var InterwikiLinks = document.getElementById( "p-lang" ).getElementsByTagName( "li" );
 
         for ( var i = 0; i < InterwikiLinks.length; i++ ) {
             if ( document.getElementById( InterwikiLinks[i].className + "-fa" ) ) {
                 InterwikiLinks[i].className += " FA"
                 InterwikiLinks[i].title = "Este artigo recebeu estatuto de destaque.";
             }
         }
     }
 }
 
 addOnloadHook( LinkFA );
/** Link bom ***************************************************************************
  *  Descrição: Adiciona estrela prateada ao lado da ligação dos artigos bons das outras Wikipédias
  ********************************************************************************************/
function Bominterwiki() 
 {
     if ( document.getElementById( "p-lang" ) ) {
         var InterwikiLinks = document.getElementById( "p-lang" ).getElementsByTagName( "li" );
 
         for ( var i = 0; i < InterwikiLinks.length; i++ ) {
             if ( document.getElementById( InterwikiLinks[i].className + "-bom" ) ) {
                 InterwikiLinks[i].className += " BOM"
                 InterwikiLinks[i].title = "Este artigo recebeu estatuto de bom.";
             }
         }
     }
 }
 
 addOnloadHook( Bominterwiki );


 
 /** Correlatos ******************************************************************************
  *  Descrição:Correlatos no menu lateral. Código copiado do de:wikt
  ********************************************************************************************/
 // InterProjekt-Links (vgl. [[MediaZilla:708]])
  document.write('<style type="text/css">#interProject, #sisterProjects {display: none; speak: none;} #p-tb .pBody {padding-right: 0;}<\/style>');
 function iProject() {
  if (document.getElementById("interProject")) {
   var iProject = document.getElementById("interProject").innerHTML;
   var interProject = document.createElement("div");
   interProject.style.marginTop = "0.7em";
   interProject.innerHTML = '<h5>Correlatos<\/h5><div class="pBody body">'+iProject+'<\/div>';
   document.getElementById("p-tb").appendChild(interProject);
  }
 }
 addOnloadHook(iProject);
 


 /** Altera o título da página **************************************************************
  *    Origem: [[:w:en:MediaWiki:Common.js]]
  * Descrição: A função procura por um banner como:
  * <nowiki><div id="RealTitleBanner">Div that is hidden</nowiki>
  *   <nowiki><span id="RealTitle">title</span></nowiki>
  * <nowiki></div></nowiki>
  * An element with id=DisableRealTitle disables the function.
  ********************************************************************************************/

 rewritePageH1 = function() {
    try {
        var realTitleBanner = document.getElementById("RealTitleBanner");
        if (realTitleBanner) {
            if (!document.getElementById("DisableRealTitle")) {
                var realTitle = document.getElementById("RealTitle");
                var h1 = document.getElementsByTagName("h1")[0];
                if (realTitle && h1) {
                    h1.innerHTML = realTitle.innerHTML;
                    realTitleBanner.style.display = "none";
                }
            }
        }
    } 
 catch (e) {
    /* Algo deu errado. */
    }
 }
 addOnloadHook(rewritePageH1);


 /** Wiki Mini Atlas ************************************************************************
  *  Descrição: Mini atlas para artigos com geocoodernadas.
  *      Autor: [[en:User:Dschwen]]
  ********************************************************************************************/

if (wgServer == "https://secure.wikimedia.org") {
  var metaBase = "https://secure.wikimedia.org/wikipedia/meta";
} else {
  var metaBase = "http://meta.wikimedia.org";
}
importScriptURI(metaBase+"/w/index.php?title=MediaWiki:Wikiminiatlas.js&action=raw&ctype=text/javascript&smaxage=21600&maxage=86400")


/** Mobile Redirect Helper ************************************************
 *
 *  Redirecionana para o gateway optimizado para sistemas móveis em pt.m.wikipedia.org
 *  para visualizadores em iPhone, iPod Touch, Palm Pre, e Android.
 *
 *  Você pode desativar o redirecionamento setando o cookie "stopMobileRedirect=true"
 *
 *  Mantenedores: [[en:User:Brion VIBBER]], [[en:User:hcatlin]]
 */
if (/(Android|iPhone|iPod|webOS|NetFront|Opera Mini|SEMC-Browser|PlayStation Portable|Nintendo Wii)/.test(navigator.userAgent)) {

  var wgMainPageName = 'Página_principal';
 
  var stopMobileRedirectCookieExists = function() {
    return (document.cookie.indexOf("stopMobileRedirect=true") >= 0);
  }
 
  var mobileSiteLink = function() {
    if ( (wgCanonicalNamespace == 'Special' || wgCanonicalNamespace == 'Especial') && (wgCanonicalSpecialPageName == 'Search' || wgCanonicalSpecialPageName == 'Busca') ) {
        var pageLink = '?search=' + encodeURIComponent(document.getElementById('searchText').value);
    } else if (wgPageName == wgMainPageName) {
        var pageLink = '::Home'; // Special case
    } else {
        var pageLink = encodeURIComponent(wgPageName).replace('%2F','/').replace('%3A',':');
    }
    return 'http://' + wgContentLanguage + '.m.wikipedia.org/wiki/' + pageLink + "?wasRedirected=true"
  }
 
  if (!stopMobileRedirectCookieExists()) {
    document.location = mobileSiteLink();
  }
}


 /** Collapsible tables *********************************************************
  *
  *  Description: Allows tables to be collapsed, showing only the header. See
  *               [[Wikipedia:NavFrame]].
  *  Maintainers: [[User:R. Koot]]
  */


 var autoCollapse = 2;
 var collapseCaption = "Esconder";
 var expandCaption = "Expandir";
 
 function collapseTable( tableIndex )
 {
     var Button = document.getElementById( "collapseButton" + tableIndex );
     var Table = document.getElementById( "collapsibleTable" + tableIndex );
 
     if ( !Table || !Button ) {
         return false;
     }
 
     var Rows = Table.rows;
 
     if ( Button.firstChild.data == collapseCaption ) {
         for ( var i = 1; i < Rows.length; i++ ) {
             Rows[i].style.display = "none";
         }
         Button.firstChild.data = expandCaption;
     } else {
         for ( var i = 1; i < Rows.length; i++ ) {
             Rows[i].style.display = Rows[0].style.display;
         }
         Button.firstChild.data = collapseCaption;
     }
 }
 
 function createCollapseButtons()
 {
     var tableIndex = 0;
     var NavigationBoxes = new Object();
     var Tables = document.getElementsByTagName( "table" );
 
     for ( var i = 0; i < Tables.length; i++ ) {
         if ( hasClass( Tables[i], "collapsible" ) ) {
 
             /* only add button and increment count if there is a header row to work with */
             var HeaderRow = Tables[i].getElementsByTagName( "tr" )[0];
             if (!HeaderRow) continue;
             var Header = HeaderRow.getElementsByTagName( "th" )[0];
             if (!Header) continue;
 
             NavigationBoxes[ tableIndex ] = Tables[i];
             Tables[i].setAttribute( "id", "collapsibleTable" + tableIndex );
 
             var Button     = document.createElement( "span" );
             var ButtonLink = document.createElement( "a" );
             var ButtonText = document.createTextNode( collapseCaption );
 
             Button.style.styleFloat = "right";
             Button.style.cssFloat = "right";
             Button.style.fontWeight = "normal";
             Button.style.textAlign = "right";
             Button.style.width = "6em";
 
             ButtonLink.style.color = Header.style.color;
             ButtonLink.setAttribute( "id", "collapseButton" + tableIndex );
             ButtonLink.setAttribute( "href", "javascript:collapseTable(" + tableIndex + ");" );
             ButtonLink.appendChild( ButtonText );
 
             Button.appendChild( document.createTextNode( "[" ) );
             Button.appendChild( ButtonLink );
             Button.appendChild( document.createTextNode( "]" ) );
 
             Header.insertBefore( Button, Header.childNodes[0] );
             tableIndex++;
         }
     }
 
     for ( var i = 0;  i < tableIndex; i++ ) {
         if ( hasClass( NavigationBoxes[i], "collapsed" ) || ( tableIndex >= autoCollapse && hasClass( NavigationBoxes[i], "autocollapse" ) ) ) {
             collapseTable( i );
         }
     }
 }
 
 addOnloadHook( createCollapseButtons );
 
 /** Dynamic Navigation Bars (experimental) *************************************
  *
  *  Description: See [[Wikipedia:NavFrame]].
  *  Maintainers: UNMAINTAINED
  */
 
  // set up the words in your language
  var NavigationBarHide = '[' + collapseCaption + ']';
  var NavigationBarShow = '[' + expandCaption + ']';
 
  // shows and hides content and picture (if available) of navigation bars
  // Parameters:
  //     indexNavigationBar: the index of navigation bar to be toggled
  function toggleNavigationBar(indexNavigationBar)
  {
     var NavToggle = document.getElementById("NavToggle" + indexNavigationBar);
     var NavFrame = document.getElementById("NavFrame" + indexNavigationBar);
 
     if (!NavFrame || !NavToggle) {
         return false;
     }
 
     // if shown now
     if (NavToggle.firstChild.data == NavigationBarHide) {
         for (
                 var NavChild = NavFrame.firstChild;
                 NavChild != null;
                 NavChild = NavChild.nextSibling
             ) {
             if ( hasClass( NavChild, 'NavPic' ) ) {
                 NavChild.style.display = 'none';
             }
             if ( hasClass( NavChild, 'NavContent') ) {
                 NavChild.style.display = 'none';
             }
         }
     NavToggle.firstChild.data = NavigationBarShow;
 
     // if hidden now
     } else if (NavToggle.firstChild.data == NavigationBarShow) {
         for (
                 var NavChild = NavFrame.firstChild;
                 NavChild != null;
                 NavChild = NavChild.nextSibling
             ) {
             if (hasClass(NavChild, 'NavPic')) {
                 NavChild.style.display = 'block';
             }
             if (hasClass(NavChild, 'NavContent')) {
                 NavChild.style.display = 'block';
             }
         }
     NavToggle.firstChild.data = NavigationBarHide;
     }
  }
 
  // adds show/hide-button to navigation bars
  function createNavigationBarToggleButton()
  {
     var indexNavigationBar = 0;
     // iterate over all < div >-elements 
     var divs = document.getElementsByTagName("div");
     for(
             var i=0; 
             NavFrame = divs[i]; 
             i++
         ) {
         // if found a navigation bar
         if (hasClass(NavFrame, "NavFrame")) {
 
             indexNavigationBar++;
             var NavToggle = document.createElement("a");
             NavToggle.className = 'NavToggle';
             NavToggle.setAttribute('id', 'NavToggle' + indexNavigationBar);
             NavToggle.setAttribute('href', 'javascript:toggleNavigationBar(' + indexNavigationBar + ');');
 
             var NavToggleText = document.createTextNode(NavigationBarHide);
             for (
                  var NavChild = NavFrame.firstChild;
                  NavChild != null;
                  NavChild = NavChild.nextSibling
                 ) {
                 if ( hasClass( NavChild, 'NavPic' ) || hasClass( NavChild, 'NavContent' ) ) {
                     if (NavChild.style.display == 'none') {
                         NavToggleText = document.createTextNode(NavigationBarShow);
                         break;
                     }
                 }
             }
 
             NavToggle.appendChild(NavToggleText);
             // Find the NavHead and attach the toggle link (Must be this complicated because Moz's firstChild handling is borked)
             for(
               var j=0; 
               j < NavFrame.childNodes.length; 
               j++
             ) {
               if (hasClass(NavFrame.childNodes[j], "NavHead")) {
                 NavFrame.childNodes[j].appendChild(NavToggle);
               }
             }
             NavFrame.setAttribute('id', 'NavFrame' + indexNavigationBar);
         }
     }
  }
 
  addOnloadHook( createNavigationBarToggleButton );


 /* Test if an element has a certain class **************************************
  *
  * Description: Uses regular expressions and caching for better performance.
  * Maintainers: [[User:Mike Dillon]], [[User:R. Koot]], [[User:SG]]
  */
 
 var hasClass = (function () {
     var reCache = {};
     return function (element, className) {
         return (reCache[className] ? reCache[className] : (reCache[className] = new RegExp("(?:\\s|^)" + className + "(?:\\s|$)"))).test(element.className);
     };
 })();






 /** Caixa com abas - [[Predefinição:Metacaixa]] *********************************************
  *    Origem: [[:w:fr:MediaWiki:Common.js]] (traduzido de [[:w:ca:MediaWiki:Common.js]])
  * Descrição: Ver [[Predefinição:Metacaixa]]
  *     Autor: [[:w:ca:User:Peleguer]], [[:w:ca:User:Joanjoc]], [[:w:fr:User:Antaya]] (adaptação), [[:w:pt:Rei-artur]] (adaptação)
  ********************************************************************************************/
function CadreOngletInit(){
 // retour si ailleurs que sur l'espace utilisateur, 
 // sachant que c'est une horreur au niveau de l'accessibilité
 // et qu'il est impossible de "récupérer" ou de recycler ce script
 // (celui-ci fonctionnant par inclusion de sous pages)
 if ( wgNamespaceNumber == 0 || wgNamespaceNumber == 102 ) return;  
  var i=0       
  for (i=0;i<=9;i++){
     var vMb = document.getElementById("mb"+i);
     if (!vMb) break;
 
     var j=1    
     var vOgIni = 0  
     for (j=1;j<=9;j++){
        var vBt = document.getElementById("mb"+i+"bt"+j);
        if (!vBt) break;
        vBt.onclick = CadreOngletVoirOnglet;          
        if (vBt.className=="mbBoutonSel") vOgIni=j;  
     }
 
     if (vOgIni == 0) { 
         vOgIni = 1+Math.floor((j-1)*Math.random()) ;
         document.getElementById("mb"+i+"og"+vOgIni).style.display = "block";
         document.getElementById("mb"+i+"og"+vOgIni).style.visibility = "visible";
         document.getElementById("mb"+i+"bt"+vOgIni).className="mbBoutonSel";
     } 
  }
 }
 
 function CadreOngletVoirOnglet(){
  var vMbNom = this.id.substr(0,3); 
  var vIndex = this.id.substr(5,1); 
 
  var i=1
  for (i=1;i<=9;i++){        
        var vOgElem = document.getElementById(vMbNom+"og"+i);
        if (!vOgElem) break;
        if (vIndex==i){ 
                vOgElem.style.display = "block";
                vOgElem.style.visibility = "visible";
                document.getElementById(vMbNom+"bt"+i).className="mbBoutonSel";
        } else {             
                vOgElem.style.display = "none";
                vOgElem.style.visibility = "hidden";
                document.getElementById(vMbNom+"bt"+i).className="mbBouton";
        }
  }
  return false; 
 }
 
 addOnloadHook(CadreOngletInit);

/* CÓDIGO JAVASCRIPT DE "METACAIXA" */



 /** ***************************************************************************
  *  Descrição: Adiciona a predefinição {protegido} e {protegido-ip} automáticos para artigos protegidos
  *  Autor: [[:pt:User:Rei-artur]]
  ******************************************************************************/
 importScript('MediaWiki:Topicon.js')


/** Banners para dicas e doações vista apenas por anônimos **************************
    *  Descrição: Frases aleatórias que podem ser vistas por anônimos the bug:
    *  Autores: [[:en:User:Gmaxwell]], [[:en:User:MZMcBride]]
  ******************************************************************************/
 importScript('MediaWiki:WikiBanners.js')


/*
 * Descrição: Manter no servidor seguro quem se loga pelo servidor seguro quando muda para outro projeto
 *            Sem este código, o usuário logado por https quando segue um interwiki, usa http e será deslogado (os logins são independentes).
 */
if(wgServer == 'https://secure.wikimedia.org') {
    importScript( 'MediaWiki:Common.js/secure.js');
}

//</source>

/* MediaWiki:Monobook.js */
/* Obsoleto. Substituído por [[MediaWiki:Common.js]] */