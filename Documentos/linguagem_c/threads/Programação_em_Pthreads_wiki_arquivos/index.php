/* generated javascript */
var skin = 'monobook';
var stylepath = '/skins-1.5';

/* MediaWiki:Common.js */
//<source lang="javascript">

/* Qualquer código JavaScript presente aqui será carregado para todos os colaboradores do Wikilivros */
 
/* Importa mais scripts específicos se for necessário */ 
if (wgAction == "edit" || wgAction == "submit" || wgPageName == "Especial:Carregar_imagem") //scripts para as páginas de edição
{
    importScript("MediaWiki:Common.js/edit.js")
}
else if (wgPageName == "Especial:Busca") //scripts para a página de buscas
{
    importScript("MediaWiki:Common.js/search.js")
}



/** Variável global para uso em scripts que lidam com o nome dos livros **
 *      Origem: [[b:en:MediaWiki:Gadget-predef.js]]
 * Mantido por: [[User:Heldergeovane]] (e o original, por [[b:en:User:Whiteknight]])
 *    Exemplo: 'A:B:C:D/E:F:G:H/I:J:K:L' -> 'A:B:C:D' -> 'A:B'
 */

var wgBookName = wgPageName.split("/", 1)[0] || wgPageName;
wgBookName = wgBookName.split(':', 2).join(":");



/** Testa se um elemento tem certa classe **
 * Description: Usa expressões regulares e caching para melhor performance.
 * Mantido por: [[w:en:User:Mike Dillon]], [[w:en:User:R. Koot]], [[w:en:User:SG]]
 */

var hasClass = (function () {
    var reCache = {};
    return function (element, className) {
        return (reCache[className] ? reCache[className] : (reCache[className] = new RegExp("(?:\\s|^)" + className + "(?:\\s|$)"))).test(element.className);
    };
})();



if (wgNamespaceNumber == 0) //scripts para o domínio principal
{
    /** Link destaque **
     *  Descrição: Adiciona estrela ao lado da ligação dos artigos destacados das outras Wikipédias
     */
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
}



function addLoadEvent(func)
{
    if (window.addEventListener)
    window.addEventListener("load", func, false);
    else if (window.attachEvent)
    window.attachEvent("onload", func);
}



/** Correlatos **
 *  Descrição: Correlatos no menu lateral. Código copiado do de:wikt
 */
// InterProjekt-Links (vgl. [[MediaZilla:708]])
document.write('<style type="text/css">#interProject {display: none; speak: none;} #p-tb .pBody {padding-right: 0;}<\/style>');
function iProject() {
    if (document.getElementById("interProject")) {
        var iProject = document.getElementById("interProject").innerHTML;
        var interProject = document.createElement("div");
        interProject.style.marginTop = "0.7em";
        interProject.innerHTML = '<h5>Correlatos<\/h5><div class="pBody">'+iProject+'<\/div>';
        document.getElementById("p-tb").appendChild(interProject);
    }
}
hookEvent("load", iProject);



/** Wiki Mini Atlas **
 *  Descrição: Mini atlas para artigos com geocoodernadas.
 *      Autor: [[en:User:Dschwen]]
 */
document.write('<script type="text/javascript" src="'
+ 'http://meta.wikimedia.org/w/index.php?title=MediaWiki:Wikiminiatlas.js'
+ '&action=raw&ctype=text/javascript&dontcountme=s"></script>');
var wma_settings =
{
    height : 300,
    width : 500
}

if(document.getElementById && !document.location.href.match("action=edit") && !document.location.href.match("action=submit")) {
    function loadLoginForm() {
        var box = document.getElementById("irclogin");
        var html = null;
        if(box) {
            html  = '<form method="post" action="http://chatwikizine.memebot.com/cgi-bin/cgiirc/irc.cgi" target="_blank" id="loginform" name="loginform">';
            html += '  <input type="hidden" id="interface" "name="interface" value="nonjs"/>';
            html += '  <input type="text" size="25" id="Nickname" name="Nickname" value="' + nickify(wgUserName) + '" onfocus="clear_text(this)"/>';
            html += '  <select id="metodo" name="metodo" onChange="setServer();"> <option value="cgi">CGI</option><option value="Java">Java</option> </select>';
            html += '  <input type="hidden" name="Character_set" value="utf-8"/>';
            html += '  <input type="hidden" id="rede" name="Server" value="irc.freenode.net"/>';
            html += '  <input type="hidden" id="ch" name="Channel" value="#wikipedia-pt"/>';
            html += '  <input type="submit" value="entrar" onclick="document.getElementById(\'loginform\').submit();"/>';
            html += '</form>';
            box.innerHTML = html;
        }
    }
    function setServer() {
        var selMetodo=document.getElementById("metodo");
        var nmMetodo=selMetodo.options[selMetodo.selectedIndex].value;
        if(nmMetodo == 'Java') {
            document.getElementById("rede").name = 'h';
            document.getElementById("Nickname").name = 'n';
            document.getElementById("ch").name = 'ch';
            document.getElementById("loginform").action = 'http://czat.computerserv.pl/';
        }else if(nmMetodo == 'cgi') {
            document.getElementById("rede").name = 'Server';
            document.getElementById("Nickname").name = 'Nickname';
            document.getElementById("ch").name = 'Channel';
            document.getElementById("loginform").action = 'http://chatwikizine.memebot.com/cgi-bin/cgiirc/irc.cgi';
        }
        setjs();
    }


    function nickify(s) {
        if(s == null) {
            return "anon" + Math.floor(Math.random()*100);
        }
        s = s.toLowerCase();
        s = s.replace(" ", "_");
        s = s.replace(/á/g, 'a');
        s = s.replace(/é/g, 'e');
        s = s.replace(/í/g, 'i');
        s = s.replace(/[óo]/g, 'o');
        s = s.replace(/[úu]/g, 'u');
        s = s.replace(/[^a-z0-9_-]/g, '');
        return s;
    }

    var irclogin_cleared = 0;
    function clear_text(field) {
        if(irclogin_cleared == 0) {
            irclogin_cleared = 1;
            field.value = "";
        }
    }
    function setjs() {
        if(navigator.product == 'Gecko') {
            document.loginform["interface"].value = 'mozilla';
        } else if(window.opera && document.childNodes) {
            document.loginform["interface"].value = 'opera7';
        } else if(navigator.appName == 'Microsoft Internet Explorer' &&
                navigator.userAgent.indexOf("Mac_PowerPC") > 0) {
            document.loginform["interface"].value = 'konqueror';
        } else if(navigator.appName == 'Microsoft Internet Explorer') {
            document.loginform["interface"].value = 'ie';
        } else if(navigator.appName == 'Konqueror') {
            document.loginform["interface"].value = 'konqueror';
        } else if(window.opera) {
            document.loginform["interface"].value = 'opera';
        }
    }

    addOnloadHook(loadLoginForm);
}

/* Scripts específicos para o Internet Explorer */

if (navigator.appName == "Microsoft Internet Explorer")
{
    /**
     *  Descrição: Corrige bug na barra de rolagem do IE
     *  Mantido por: [[User:Tom-]]?
     */
    var oldWidth;
    var docEl = document.documentElement;

    function fixIEScroll()
    {
        if (!oldWidth || docEl.clientWidth > oldWidth)
        doFixIEScroll();
        else
        setTimeout(doFixIEScroll, 1);

        oldWidth = docEl.clientWidth;
    }

    function doFixIEScroll() {
        docEl.style.overflowX = (docEl.scrollWidth - docEl.clientWidth < 4) ? "hidden" : "";
    }

    document.attachEvent("onreadystatechange", fixIEScroll);
    document.attachEvent("onresize", fixIEScroll);

    //Importa os scripts específicos para o Internet Explorer 6
    if (navigator.appVersion.substr(22, 1) == "6") {
        importScript("MediaWiki:Common.js/IE60Fixes.js")
    }
}



/** Barra de navegação **
 *    Descrição: Veja [[w:en:Wikipedia:NavFrame]]
 *  Mantido por: NÃO É MANTIDO!
 */
// set up the words in your language
var NavigationBarHide = '[ Esconder ]';
var NavigationBarShow = '[ Expandir ]';

// set up max count of Navigation Bars on page,
// if there are more, all will be hidden
// NavigationBarShowDefault = 0; // all bars will be hidden
// NavigationBarShowDefault = 1; // on pages with more than 1 bar all bars will be hidden
var NavigationBarShowDefault = 1;


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
            if (NavChild.className == 'NavPic') {
                NavChild.style.display = 'none';
            }
            if (NavChild.className == 'NavContent') {
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
            if (NavChild.className == 'NavPic') {
                NavChild.style.display = 'block';
            }
            if (NavChild.className == 'NavContent') {
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
    for(
    var i=0;
    NavFrame = document.getElementsByTagName("div")[i];
    i++
    ) {
        // if found a navigation bar
        if (NavFrame.className == "NavFrame") {

            indexNavigationBar++;
            var NavToggle = document.createElement("a");
            NavToggle.className = 'NavToggle';
            NavToggle.setAttribute('id', 'NavToggle' + indexNavigationBar);
            NavToggle.setAttribute('href', 'javascript:toggleNavigationBar(' + indexNavigationBar + ');');

            var NavToggleText = document.createTextNode(NavigationBarHide);
            NavToggle.appendChild(NavToggleText);
            // Find the NavHead and attach the toggle link (Must be this complicated because Moz's firstChild handling is borked)
            for(
            var j=0;
            j < NavFrame.childNodes.length;
            j++
            ) {
                if (NavFrame.childNodes[j].className == "NavHead") {
                    NavFrame.childNodes[j].appendChild(NavToggle);
                }
            }
            NavFrame.setAttribute('id', 'NavFrame' + indexNavigationBar);
        }
    }
    // if more Navigation Bars found than Default: hide all
    if (NavigationBarShowDefault < indexNavigationBar) {
        for(
        var i=1;
        i<=indexNavigationBar;
        i++
        ) {
            toggleNavigationBar(i);
        }
    }

}

addLoadEvent(createNavigationBarToggleButton);



/** Collapsible Tables **
 *    Origem: [[w:en:MediaWiki:Common.js]]
 *     Ajuda: [[w:en:Wikipedia:Collapsible_tables]]
 * Descrição: Permite que tabelas sejam recolhidas/expandidas
 *   Autores: [[w:en:User:R. Koot]]
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
 
            Button.className = "collapseButton";  //Styles are declared in Common.css
 
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
        else if ( hasClass( NavigationBoxes[i], "innercollapse" ) ) {
            var element = NavigationBoxes[i];
            while (element = element.parentNode) {
                if ( hasClass( element, "outercollapse" ) ) {
                    collapseTable ( i );
                    break;
                }
            }
        }
    }
}
 
addOnloadHook( createCollapseButtons );



/** Adiciona ou remove um evento a um objeto específico **
 * Cross-browser event attachment (John Resig)
 * http://www.quirksmode.org/blog/archives/2005/10/_and_the_winner_1.html
 *
 * obj  : Objeto DOM ao qual o evento será adicionado
 * type : String, tipo de evento ("click", "mouseover", "submit", etc.)
 * fn   : Função a ser chamada quando o evento é disparado (a palavra-chave ''this''
 *        aponta para o ''obj'' dentro de ''fn'' quando o evento é disparado)
 *
 * Mantido localmente por: [[User:Heldergeovane]]
 */
function addEvent( obj, type, fn )
{
    if (obj.addEventListener)
    obj.addEventListener( type, fn, false );
    else if (obj.attachEvent)
    {
        obj["e"+type+fn] = fn;
        obj[type+fn] = function() { obj["e"+type+fn]( window.event ); }
        obj.attachEvent( "on"+type, obj[type+fn] );
    }
}
function removeEvent( obj, type, fn )
{
    if (obj.removeEventListener)
    obj.removeEventListener( type, fn, false );
    else if (obj.detachEvent)
    {
        obj.detachEvent( "on"+type, obj[type+fn] );
        obj[type+fn] = null;
        obj["e"+type+fn] = null;
    }
}
//</source>

/* MediaWiki:Monobook.js */
/** Transforma determinadas páginas em páginas de discussão ***************************************************
  *    Origem: [[fr:w:MediaWiki:Common.js]]
  * Descrição: Transforma páginas comuns em páginas de discussão, para permitir coloração baseada na indentação
  *   Autores: ver [[fr:w:MediaWiki:Common.js]]
  *************************************************************************************************************/
 
function TransformeEmPaginaDeDiscussao() {
  if(document.getElementById('PaginaDeDiscussao'))
    document.body.className = 'ns-talk';
}
addOnloadHook(TransformeEmPaginaDeDiscussao);