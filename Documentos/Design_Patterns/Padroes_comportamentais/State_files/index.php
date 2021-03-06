// <source lang="css">

/* Correct <sub> and <sup> aligns for IE */
sup,
sub {  height: 0;
line-height: 1;
vertical-align: baseline;
_vertical-align: bottom;
position: relative;
}
sup {  bottom: 1ex;
}
sub {  top: .5ex;
}

/* Don't display some stuff on the main page */
 /* Don't display some stuff on the main page */
 body.page-Página_principal #t-cite,
 body.page-Página_principal #lastmod, 
 body.page-Página_principal #siteSub, 
 body.page-Página_principal #contentSub, 
 body.page-Página_principal h1.firstHeading {
     display: none !important;}



 div.editsection {
   text-transform: lowercase;
 }


 /* Imagem para interlinks de artigos destacados e bons */
li.FA {
  list-style-image: url("http://upload.wikimedia.org/wikipedia/en/d/d4/Monobook-bullet-star.png");
}

li.BOM {
   list-style-image: url("http://upload.wikimedia.org/wikipedia/commons/a/a1/Monobook-bullet-star-gray.png");
}

/* Resultados de busca */
.mw-search-results {
   margin-left: 0;
}
.mw-search-results li {
 margin: 0;
 padding: 0.35em 1em;
 border-bottom: 1px solid #d3daed;
 background-color: #f6f8fc;
 list-style-type: none;
 list-style-image: none;
}
.mw-search-results table {
   background-color: transparent;
}
.mw-search-result-data {
   color: #008000;
}

/* Cores alternadas para as listas especiais (mudanças recentes, vigidaos, etc.) */
.mw-line-odd { background-color: #ffffff;}
.mw-line-even { background-color: #f5f5f5;}

  /* 
==modelos de predefinições==
 */


 /* infobox */
 .infobox {
   border: 1px solid #aaaaaa;
   background-color: #f9f9f9;
   margin-bottom: 0.5em;
   margin-left: 1em; 
   padding: .2em;
   float: right;
   clear: right;
 }
 .infobox tr {
   vertical-align: top;
 }
 .infobox caption {
   margin-left: inherit;
 }
 .infobox.bordered {
   border-collapse: collapse;
 }
 .infobox.bordered td, .infobox.bordered th {
   border: 1px solid #aaaaaa;
 }
 .infobox.sisterproject {
   width: 22em;
 }

 /* hiddenStructure from Monobook - allows selective hiding of markup in templates */
 .hiddenStructure {
   display: none;
 }





 /* prettytable */
 table.wikitable,
 table.prettytable {
   margin: 1em 1em 1em 0;
   background: #f9f9f9;
   border: 1px #aaaaaa solid;
   border-collapse: collapse;
 }
 
 table.wikitable th, table.wikitable td,
 table.prettytable th, table.prettytable td {
   border: 1px #aaaaaa solid;
   padding: 0.2em;
 }
 
 table.wikitable th,
 table.prettytable th {
   background: #f2f2f2;
   text-align: center;
 }
 
 table.wikitable caption,
 table.prettytable caption {
   margin-left: inherit;
   margin-right: inherit;
 }




/*predefinições informativas e mensagens MediaWiki*/
.caixa {
    width: 80%;
    margin: 0 auto;
    padding: .1em;
    font-size:95%;
}
.caixaMW {
    margin: 1px 0;
    padding: .1em;
    font-size: 93%;
    line-height:120%;
    clear: both;
}
.caixaMW.info,
.caixa.info {
    background-color: white;
    border: 1px solid #ccc;
}
.caixaMW.infodestaque,
.caixa.infodestaque {
    background-color: #f5faff;
    border: 1px solid #cedff2;
}
.caixaMW.aviso,
.caixa.aviso {
    background-color:#fff3f3;
    border: 1px solid #ffc9c9;
}
.caixaMW.avisodestaque,
.caixa.avisodestaque {
    background-color:#fff;
    border: 2px solid #f00;
}






 /* for MediaWiki:Sharedupload */
 #sharedupload-warn {
  width: 100%;
  clear: right;
  border: 1px solid gray;
  background: #f9f9f9;
  margin: 0 0 1em 0;
  padding: 4px;
  font-size: 90%;
  text-align: left;
  float: left;
 }



/* skin padrão para caixas de navegação (navbox) */
table.navbox {
    background-color: #f9f9f9;
    border: 1px solid #aaa;
    clear: both;
    font-size: 90%;
    margin: 1em 0em 0em;
    padding: 2px;
    text-align: center;
    width: 100%;
}

table.navbox th {
    background-color: #ccf;
    padding-left: 1em;
    padding-right: 1em;
}

table.navbox tr:not(:first-child) th {
    background-color: #ddf;
}

@media print {
    .navbox {
        display: none;
    }
}

 /*  Barra de navegação  */
div.Boxmerge,
div.NavFrame {
        margin: 0px;
        padding: 2px;
        border: 1px solid #aaaaaa;
        text-align: center;
        border-collapse: collapse;
        font-size: 95%;
}
div.Boxmerge div.NavFrame {
        border-style: none;
        border-style: hidden;
}
div.NavFrame + div.NavFrame {
        border-top-style: none;
        border-top-style: hidden;
}
div.NavPic {
        background-color: #ffffff;
        margin: 0px;
        padding: 2px;
        float: left;
}
div.NavFrame div.NavHead {
        height: 1.6em;
        font-weight: bold;
        font-size: 100%;
        background-color: #efefef;
        position:relative;
}
div.NavFrame p {
        font-size: 100%;
}
div.NavFrame div.NavContent {
        font-size: 100%;
}
div.NavFrame div.NavContent p {
        font-size: 100%;
}
div.NavEnd {
        margin: 0px;
        padding: 0px;
        line-height: 1px;
        clear: both;
}
a.NavToggle {
        position:absolute;
        top:0px;
        right:3px;
        font-weight:normal;
        font-size:smaller;
}

  /* 
==Referencias==
 */

 /* make the list of references look smaller */
 ol.references {
   font-size: 100%;
 }

 /* Realce a azul das referências ''clicadas'' para ajudar na navegação */

 ol.references > li:target,
  span.citation:target {
  background-color: #DEF;
 }

 sup.reference:target { 
  background-color: #DEF;
 }

 /* Formatação de citações */
 span.citation, cite {
  font-style: normal;
  word-wrap: break-word;
 }

 /* Para números e IDs de documentos ligados, em que o número
 não precisa ser mostrado em uma tela ou computador de mão,
 mas deve ser incluído na versão impressa
 */
@media screen, handheld {
    span.citation *.printonly {
        display: none;
    }
}

 .references-small { font-size: 90%; }

/* Bloqueado até versão final do IE 8 */
/*
@media screen {
    .references-small {
        height: auto;
        max-height: 350px;
        overflow: auto;
        padding: 3px;
    }
}
*/


  /* 
==redirect em verde==
 */

 /* Faz com que os redirects apareçam em itálico e verde em [[Special:Allpages]] e [[Special:Watchlist]] */
  .allpagesredirect a,
  .unusedtemplatesredirect a,
  .watchlistredir a  {
    font-style: italic;
    color:green;
 }


  /* 
==CommonsTicker styles==
 */
  /************************/
  /* CommonsTicker styles */
  /************************/
 
  /* 
===links===
 */
  .tickerDiffLink { } /* diff links in ticker */
  .tickerMiscLink { } /* misc links in ticker */
 
  /* 
===remove list bullets===
 */
  .tickerList ul,    .tickerList ul li    { list-style: none; text-indent:-2em; margin-left:2em;   text-align:left; }
  .tickerList ul ul, .tickerList ul ul li { list-style: none; text-indent:0;    margin-left:1.5em; text-align:left; }

  /*
===per-type styles===
 */
  .tickerEntry_deleted     {font-weight: bold;}  /* entry for image deletion */
  .tickerEntry_restored    {font-size: small;}  /* entry for restored image */
  .tickerEntry_replaced    { }  /* entry for image replacement */
  .tickerEntry_tagged      { }  /* entry for adding/removing problem tags */
  .tickerEntry_redir       { }  /* entry for critical redirection (fot tag redirects) */
  .tickerEntry_recat       { }  /* entry for critical re-categorization (for tag categories) */
  .tickerEntry_notify      { }  /* entry for global notifications */
  .tickerEntry_changed     { }  /* entry for generic change */

  /* 
===per-action styles===
 */
  .tickerAction_deleted:before     { content:" GONE "; color: #FF0000; font-family:monospace; font-weight:bold; font-size:100%; }  
  .tickerAction_restored:before    { content:" BACK "; color: #00BB00; font-family:monospace; font-weight:bold; font-size:100%; }  
  .tickerAction_deletedRev:before  { content:" -OLD "; color: #DDAAAA; font-family:monospace; font-weight:bold; font-size:100%; }  
  .tickerAction_replaced:before    { content:" REPL "; color: #CC88FF; font-family:monospace; font-weight:bold; font-size:100%; }  
  .tickerAction_replacedOwn:before { content:" UPDT "; color: #EEAAFF; font-family:monospace; font-weight:bold; font-size:100%; }  
  .tickerAction_addedBad:before    { content:" +VfD "; color: #FF8800; font-family:monospace; font-weight:bold; font-size:100%; }  
  .tickerAction_removedBad:before  { content:" -VfD "; color: #00BB00; font-family:monospace; font-weight:bold; font-size:100%; }  
  .tickerAction_addedGood:before   { content:" +OK  "; color: #00BB00; font-family:monospace; font-weight:bold; font-size:100%; }  
  .tickerAction_removedGood:before { content:" -OK  "; color: #FF8800; font-family:monospace; font-weight:bold; font-size:100%; }
  /* 
===per-status styles===
 */  

  .tickerStatus_done:before {content:" Fixed "; color: #00AA00; font-family:monospace; font-weight:bold; font-size:90%; text-decoration: none;}
  .tickerStatus_done {text-decoration:line-through; font-size: small; } 
/*
==== strike through when entry has been handeled (done)====
 */
  /*.tickerStatus_done .tickerAction_deleted:before  { content:" "; text-decoration: none;}*/ 
  .tickerStatus_done .tickerAction_deleted:before  {text-decoration: none;}
  /*
====local reupload====
 */  
  .tickerStatus_local {text-decoration:line-through; font-size: small; } 
  .tickerStatus_local .tickerAction_deleted:before  {content:" "; text-decoration: none;}
  .tickerStatus_local:before {content:" re-uploaded locally "; color: #00AA00; font-family:monospace; font-weight:bold; font-size:90%; text-decoration: none;}
  /*
====dados pessoais====
 */
  table.metadata {
    border: 1px solid #aaa;
    display: none;
    speak: none;
 }
  .metadata-label {
    color: #aaa;
 }
  /*
====in process of fixing====
 */
  .tickerStatus_fixing .tickerAction_deleted:before  {content:" "; text-decoration: none;}
  .tickerStatus_fixing:before {content:"fixing"; color: #FF8800; font-family:monospace; font-weight:bold; font-size:90%;}
/*
====Won'tfix====
*/
  .tickerStatus_wontfix .tickerAction_deleted:before  {text-decoration: none;}
  .tickerStatus_wontfix {text-decoration: line-through;}
  .tickerStatus_wontfix:before {content:"Will not fix"; color: #CC0000; font-family:monospace; font-weight:bold; font-size:90%;text-decoration:none;}  
/*
====similiar====
*/
  .tickerStatus_similiar .tickerAction_deleted:before  {text-decoration: none;}
  .tickerStatus_similiar {text-decoration: line-through;}
  .tickerStatus_similiar:before {content:"REPL Article;no fix"; color: #FF4400; font-family:monospace; font-weight:bold; font-size:90%;text-decoration:none;}
/*
====NA====
*/
  .tickerStatus_NA .tickerAction_deleted:before  {text-decoration: none;}
  .tickerStatus_NA:before {content:"No NEG"; color: #00FF20;} 
  ul span.tickerStatus_NA + ul span.tickerUsage {display:none;}
  span.tickerStatus_NA  span.tickerUsage {display:none;}
/*Needed so that both subentrys and non-subentrys both are invisivble */

/*
=== ticker usage list===
 */

  .tickerUsage  { font-size:80%; }  

  /* entry applies to a template used by multiple images */
  .tickerTemplateEntry    { font-weight: bold; } 

  /* entry applies to sub-entries, i.e. images that use a specific template */
  .tickerSubEntry         { }                       

  /* minor entry styles */ 
  .tickerMinorEntry  { color:#666; }     /* minor entry */
  .tickerMinorEntry a,
  .tickerMinorEntry a:link,
  .tickerMinorEntry a:visited { color:#669; }
  #bodyContent .tickerMinorEntry a.extiw,
  #bodyContent .tickerMinorEntry a.extiw:link,
  #bodyContent .tickerMinorEntry a.extiw:visited { color:#669; }



/*****
** styles for Template:Creator (utilisé par commons. Répare la perte du style)
*****/ 
 table.creator { text-align:left; border-collapse:collapse; background-color:#F0F0FF; }
 table.creator th { background: #E0E0EE;  vertical-align: top; }
 table.creator td { background: #F0F0FF; vertical-align: top; }
 table.creator td.creator-name { font-weight: bold; }

/* Íconpara predefinições medialist [[Template:Ouça]], [[Template:Multi-listen_start]], [[Template:Video]], [[Template:Multi-video_start]] */


  div.listenlist {
    background: url("http://upload.wikimedia.org/wikipedia/commons/thumb/a/a6/Gnome-speakernotes.png/30px-Gnome-speakernotes.png");
    padding-left: 40px;
  }

  div.videolist, div.multivideolist {
    background: url("http://upload.wikimedia.org/wikipedia/en/thumb/2/20/Tango-video-x-generic.png/40px-Tango-video-x-generic.png");
    padding-left: 50px;
  }

  /* Style rules for media list templates */

  div.medialist {
    min-height: 50px;
    margin: 1em;
    background-position: top left;
    background-repeat: no-repeat;
  }

  div.medialist ul {
    list-style-type: none; 
    list-style-image: none;
    margin: 0;
  }

  div.medialist ul li {
    padding-bottom: 0.5em;
  }

  div.medialist ul li li {
    font-size: 91%;
    padding-bottom: 0;
  }

/* Change the external link icon to an Adobe icon for all PDF files
   in browsers that support these CSS selectors, like Mozilla and Opera */
  #content a[href$=".pdf"].external, 
  #content a[href*=".pdf?"].external, 
  #content a[href*=".pdf#"].external,
  #content a[href$=".PDF"].external, 
  #content a[href*=".PDF?"].external, 
  #content a[href*=".PDF#"].external,
  #mw_content  a[href$=".pdf"].external, 
  #mw_content  a[href*=".pdf?"].external, 
  #mw_content  a[href*=".pdf#"].external,
  #mw_content  a[href$=".PDF"].external, 
  #mw_content  a[href*=".PDF?"].external, 
  #mw_content  a[href*=".PDF#"].external {
    background: 
        url("http://upload.wikimedia.org/wikipedia/commons/2/23/Icons-mini-file_acrobat.gif")
        center right no-repeat;
    padding-right: 16px;
 }

/* Change the external link icon to an Adobe icon anywhere the PDFlink class
   is used (notably Template:PDFlink). This works in IE, unlike the above. */
  #content span.PDFlink a,
  #mw_content span.PDFlink a {
    background: 
        url("http://upload.wikimedia.org/wikipedia/commons/2/23/Icons-mini-file_acrobat.gif")
        center right no-repeat;
    padding-right: 17px;
  }

/* Remove link styling. Already defined in monobook
   and modern, but not defined in the other skins. Bug 18708 */
  #content .plainlinks a,
  #mw_content .plainlinks a {
    background: none !important;
    padding: 0 !important;
  }

/* Messagebox templates */

.messagebox {
   border: 1px solid #aaa;
   background-color: #f9f9f9;
   width: 80%;
   margin: 0 auto 1em auto;
   padding: .2em;
}
.messagebox.merge {
   border: 1px solid #c0b8cc;
   background-color: #f0e5ff;
   text-align: center;
}
.messagebox.cleanup {
   border: 1px solid #9f9fff;
   background-color: #efefff;
   text-align: center;
}
.messagebox.standard-talk {
   border: 1px solid #c0c090;
   background-color: #f8eaba;
}
.messagebox.nested-talk {
   border: 1px solid #c0c090;
   background-color: #f8eaba;
   width: 100%;
   margin: 2px 4px 2px 4px;
}
.messagebox.small {
   width: 238px;
   font-size: 85%;
   float: right;
   clear: both;
   margin: 0 0 1em 1em;
   line-height: 1.25em; 
}

/*
</pre>
*/



 /** Caixa com abas - [[Predefinição:Metacaixa]] (definição das cores) ***********************
  *    Origem: [[:w:fr:MediaWiki:Common.css]] (traduzido de [[:w:ca:MediaWiki:Common.css]])
  * Descrição: Ver [[Predefinição:Metacaixa]]
  *     Autor: [[:w:ca:User:Peleguer]], [[:w:ca:User:Joanjoc]], [[:w:fr:User:Antaya]](adaptação) e [[:w:pt:Rei-artur]] (adaptação)
  ********************************************************************************************/
 
/*
Configuração padrão das cores 
Cores utilizadas; 1; 8080ff 2; 9f9fff 3; c4c4ff 4; ddddff 5; eaeaff */
 
.mbBouton {
  background-color: #ddddff; /* 4 */
  border: 0.15em solid #000000;
  border-color: #eaeaff #c4c4ff #9f9fff #eaeaff;  /* 5 3 2 5 */
  -moz-border-radius: .5em .5em 0em 0em;
  cursor:pointer;
  display: inline;
  margin-right: 0.1em;
  padding: 0.2em 0.3em 0.2em 0.3em;
  position: relative;}
 
.mbBouton a,
.mbBouton strong {
  background: none !important;
  color:#8080ff !important;  /* 1 */
  font-size: 90%;
  font-weight: bold;
  padding: 0 !important;
  text-decoration: none !important;}
 
.mbBouton a:hover,
.mbBouton strong:hover {
  color: black !important;
  text-decoration: underline !important;}
 
.mbBoutonSel {
  background-color: #9f9fff; /* 2 */
  border: 0.15em solid #000000;
  border-color: #c4c4ff #8080ff #9f9fff #c4c4ff;  /* 3 1 2 3 */
  -moz-border-radius: .5em .5em 0em 0em;
  cursor: default;
  display: inline;
  margin-right: 0.1em;
  padding: 0.2em 0.3em 0.2em 0.3em;
  position: relative;
  color:white;}
 
.mbBoutonSel a {
  background: none !important;
  color:white !important;
  cursor: default;
  font-size: 90%;
  font-weight: bold;
  padding: 0 !important;
  text-decoration: none !important;}
 
.mbContenu {
  background-color: #f8f8ff;
  border: 0.2em solid #9f9fff; /* 2 */
  border-color: #9f9fff #8080ff #8080ff #9f9fff ; /* 2 1 1 2 */
  -moz-border-radius: 0em .5em .5em 0em;
  padding: 1em;
  position: static;  }
 
.mbOnglet {
  background-color: #f8f8ff;
  border-color: #8080ff #c4c4ff #c4c4ff #8080ff; /* 1 3 3 1 */  width: 100%;
}
 
/* Configuration du Lilas 1;7050a0 2;9070c0 3;b090e0 4;d0b0ff 5;f0d0ff */
 
.mbLilas .mbBouton {
 background-color: #d0b0ff; /* 4 */
 border-color: #f0d0ff #b090e0 #9070c0 #f0d0ff;  /* 5 3 2 5 */}
 
.mbLilas .mbBouton a,
.mbLilas .mbBouton strong {
  color:#8080ff !important;  /* 1 */
  font-size:90%}
 
.mbLilas .mbBouton a:hover,
.mbLilas .mbBouton strong:hover {
  color: black !important;
  text-decoration: underline;}
 
.mbLilas .mbBoutonSel {
  background-color: #9070c0; /* 2 */
  border-color: #b090e0 #7050a0 #9070c0 #b090e0;  /* 3 1 2 3 */}
 
.mbLilas .mbContenu {
  background-color: #f5fffa;
  border-color: #9070c0 #7050a0 #7050a0 #9070c0 ; /* 2 1 1 2 */}
 
.mbLilas .mbOnglet {
  background-color: #f5fffa;
  border-color: #7050a0 #b090e0 #b090e0 #7050a0; /* 1 3 3 1 */}
 
 
/* Configuration du Vert 1;60b030 2;75c045 3;90d060 4;a5e085 5;c0f090 */
 
.mbVert .mbBouton {
 background-color: #a5e085; /* 4 */
 border-color: #c0f090 #90d060 #75c045 #c0f090;  /* 5 3 2 5 */}
 
.mbVert .mbBouton a,
.mbVert .mbBouton strong {
  color:#60b030 !important;  /* 1 */
  font-size:90%}
 
.mbVert .mbBouton a:hover,
.mbVert .mbBouton strong:hover {
  color: black !important;
  text-decoration: underline;}
 
.mbVert .mbBoutonSel {
  background-color: #75c045; /* 2 */
  border-color: #90d060 #60b030 #75c045 #90d060;  /* 3 1 2 3 */}
 
.mbVert .mbContenu {
  background-color: #f5fffa;
  border-color: #75c045 #60b030 #60b030 #75c045 ; /* 2 1 1 2 */}
 
.mbVert .mbOnglet {
  background-color: #f5fffa;
  border-color: #60b030 #90d060 #90d060 #60b030; /* 1 3 3 1 */}
 
 
/* Configuration du Bleu 1;3379de 2;5b8dd6 3;88abde 4;a7c1e6 5;c8d6e9 */
 
.mbBleu .mbBouton {
 background-color: #a7c1e6; /* 4 */
 border-color: #c8d6e9 #88abde #5b8dd6 #c8d6e9;  /* 5 3 2 5 */}
 
.mbBleu .mbBouton a,
.mbBleu .mbBouton strong {
  color:#3379de !important;  /* 1 */
  font-size:90%}
 
.mbBleu .mbBouton a:hover 
.mbBleu .mbBouton strong:hover {
  color: black !important;
  text-decoration: underline;}
 
.mbBleu .mbBoutonSel {
  background-color: #5b8dd6; /* 2 */
  border-color: #88abde #3379de #5b8dd6 #88abde;  /* 3 1 2 3 */}
 
.mbBleu .mbContenu {
  background-color: #f0f8ff;
  border-color: #5b8dd6 #3379de #3379de #5b8dd6; /* 2 1 1 2 */}
 
.mbBleu .mbOnglet {
  background-color: #f0f8ff;
  border-color: #3379de #88abde #88abde #3379de; /* 1 3 3 1 */}
 
 
/* Configuration du Orange 1;ff820e 2;ff9d42 3;ffac5d 4;ffbd7f 5;ffd0a4 6;ffeedd */
 
.mbOrange .mbBouton {
 background-color: #ffbd7f; /* 4 */
 border-color: #ffd0a4 #ffac5d #ff9d42 #ffd0a4;  /* 5 3 2 5 */}
 
.mbOrange .mbBouton a,
.mbOrange .mbBouton strong {
  color:#ff820e !important;  /* 1 */
  font-size:90%}
 
.mbOrange .mbBouton a:hover 
.mbOrange .mbBouton strong:hover {
  color: black !important;
  text-decoration: underline;}
 
.mbOrange .mbBoutonSel {
  background-color: #ff9d42; /* 2 */
  border-color: #ffac5d #ff820e #ff9d42 #ffac5d;  /* 3 1 2 3 */}
 
.mbOrange .mbContenu {
  background-color: #ffeedd; /* 6 */
  border-color: #ff9d42 #ff820e #ff820e #ff9d42; /* 2 1 1 2 */}
 
.mbOrange .mbOnglet {
  background-color: #ffeedd; /* 6 */
  border-color: #ff820e #ffac5d #ffac5d #ff820e; /* 1 3 3 1 */}
 
/* Configuration du Gris 1;666666 2;868686 3;9f9f9f 4;b9b9b9 5;cfcfcf */
 
.mbGris .mbBouton {
 background-color: #b9b9b9; /* 4 */
 border-color: #cfcfcf #9f9f9f #868686 #cfcfcf;  /* 5 3 2 5 */}
 
.mbGris .mbBouton a,
.mbGris .mbBouton strong {
  color:#666666 !important;  /* 1 */
  font-size:90%}
 
.mbGris .mbBouton a:hover 
.mbGris .mbBouton strong:hover {
  color: black !important;
  text-decoration: underline;}
 
.mbGris .mbBoutonSel {
  background-color: #868686; /* 2 */
  border-color: #9f9f9f #666666 #868686 #9f9f9f;  /* 3 1 2 3 */}
 
.mbGris .mbContenu {
  background-color: #fffce8;
  border-color: #868686 #666666 #666666 #868686; /* 2 1 1 2 */}
 
.mbGris .mbOnglet {
  background-color: #fffce8;
  border-color: #666666 #9f9f9f #9f9f9f #666666; /* 1 3 3 1 */}
 
 
/* Configuration du Jaune 1;aa8800 2;eabb00 3;ffd52b 4;ffe16a 5;ffeeaa */
 
.mbJaune .mbBouton {
 background-color: #ffe16a; /* 4 */
 border-color: #ffeeaa #ffd52b #eabb00 #ffeeaa;  /* 5 3 2 5 */}
 
.mbJaune .mbBouton a,
.mbJaune .mbBouton strong {
  color:#aa8800!important;  /* 1 */
  font-size:90%}
 
.mbJaune .mbBouton a:hover 
.mbJaune .mbBouton strong:hover {
  color: black !important;
  text-decoration: underline;}
 
.mbJaune .mbBoutonSel {
  background-color: #eabb00; /* 2 */
  border-color: #ffd52b #aa8800 #eabb00 #ffd52b;  /* 3 1 2 3 */}
 
.mbJaune .mbContenu {
  background-color: #fffce8;
  border-color: #eabb00 #aa8800 #aa8800 #eabb00; /* 2 1 1 2 */}
 
.mbJaune .mbOnglet {
  background-color: #fffce8;
  border-color: #aa8800 #ffd52b #ffd52b #aa8800; /* 1 3 3 1 */}
 
 
/* Configuration du Rouge 1;993300 2;ca4200 3;ff6215 4;ff9b6a 5;ffc6aa */
 
.mbRouge .mbBouton {
 background-color: #ff9b6a; /* 4 */
 border-color: #ffc6aa #ff6215 #ca4200 #ffc6aa;  /* 5 3 2 5 */}
 
.mbRouge .mbBouton a,
.mbRouge .mbBouton strong {
  color:#993300!important;  /* 1 */
  font-size:90%}
 
.mbRouge .mbBouton a:hover 
.mbRouge .mbBouton strong:hover {
  color: black !important;
  text-decoration: underline;}
 
.mbRouge .mbBoutonSel {
  background-color: #ca4200; /* 2 */
  border-color: #ff6215 #993300 #ca4200 #ff6215;  /* 3 1 2 3 */}
 
.mbRouge .mbContenu {
  background-color: #fffce8;
  border-color: #ca4200 #993300 #993300 #ca4200; /* 2 1 1 2 */}
 
.mbRouge .mbOnglet {
  background-color: #fffce8;
  border-color: #993300 #ff6215 #ff6215 #993300; /* 1 3 3 1 */}
 
/*FIN DES SCHÉMAS DE COULEUR DE "CADRE À ONGLETS"*/

/************************************************
 ***     Infobox V2 - em fase de teste        ***
 *** Ver [[fr:Projet:Infobox/V2]]             ***
 ************************************************/
 
.infobox_v2 {
 background: #f9f9f9;
 color: #000;
 font-size: 90%;
 line-height: 1.1em; 
 float:right;
 clear:right;
 margin:0 0 .5em 1em;
 width: 23em;
 border: 1px solid #aaa;
 padding: 2px;
}
 
.infobox_v2 th {
 vertical-align:top;
 text-align:left;
}
 
.infobox_v2 .topo{
 height:45px;
 vertical-align:middle;
 text-align:center;
 font-size:120%; 
 font-weight:bolder;
 line-height:1.2em;
 color:#000;
}

.infobox_v2 .midia {
height:35px;
vertical-align:middle;
text-align:center;
font-weight:bolder;
color:#000;
}
 
/* Imagens transparentes dos topos da infobox V2 */
.topo.padrao      {}
.topo.bd          {background: url("http://upload.wikimedia.org/wikipedia/commons/2/2c/Picto_infobox_comicballoon.png")  no-repeat top right;}
.topo.cerveja     {background: url("http://upload.wikimedia.org/wikipedia/commons/0/04/Picto_infobox_beer.png")          no-repeat top right;}
.topo.cinema      {background: url("http://upload.wikimedia.org/wikipedia/commons/e/ea/Picto_infobox_cinema.png")        no-repeat top right;}
.topo.comunicacao {background: url("http://upload.wikimedia.org/wikipedia/commons/a/a2/Picto_infobox_antenna.png")       no-repeat top right;}
.topo.humano      {background: url("http://upload.wikimedia.org/wikipedia/commons/8/82/Picto_infobox_manwoman.png")      no-repeat top right;}
.topo.jogo        {background: url("http://upload.wikimedia.org/wikipedia/commons/2/2d/Picto_infobox_gamepad.png")       no-repeat bottom right;}
.topo.mapa        {background: url("http://upload.wikimedia.org/wikipedia/commons/7/7a/Picto_infobox_map.png")           no-repeat top right;}
.topo.musica      {background: url("http://upload.wikimedia.org/wikipedia/commons/6/60/Picto_infobox_music.png")         no-repeat bottom right;}
.topo.teatro      {background: url("http://upload.wikimedia.org/wikipedia/commons/3/37/Picto_infobox_masks.png")         no-repeat top right;}
.topo.esporte     {background: url("http://upload.wikimedia.org/wikipedia/commons/8/8e/Picto_infobox_Olympic.png")       no-repeat top right;}
.topo.sci-fi      {background: url("http://upload.wikimedia.org/wikipedia/commons/e/ed/Picto_infobox_fliyingsaucer.png") no-repeat top right;}
.topo.autor       {background: url("http://upload.wikimedia.org/wikipedia/commons/1/1e/Picto_infobox_auteur.png")        no-repeat top right;}
.topo.animal      {background: url("http://upload.wikimedia.org/wikipedia/commons/5/54/Picto_infobox_animal.png")        no-repeat top right;}
.topo.astronomia  {background: url("http://upload.wikimedia.org/wikipedia/commons/7/71/Picto_infobox_astronomy.png")     no-repeat top right;}
.topo.quimica     {background: url("http://upload.wikimedia.org/wikipedia/commons/5/57/Picto_Info_sciences_exactes.png") no-repeat top right;}
.topo.ponte       {background: url("http://upload.wikimedia.org/wikipedia/commons/8/87/Picto_infobox_bridge.png")        no-repeat top right;}
.topo.conflito    {background: url("http://upload.wikimedia.org/wikipedia/commons/a/a5/Picto_infobox_conflict.png")      no-repeat top right;}
.topo.wiki        {background: url("http://upload.wikimedia.org/wikipedia/commons/2/24/Picto_infobox_default.png")       no-repeat top right;}
.topo.filme       {background: url("http://upload.wikimedia.org/wikipedia/commons/4/4d/Picto_infobox_film.png")          no-repeat center right;}
.topo.futebol     {background: url("http://upload.wikimedia.org/wikipedia/commons/a/a8/Picto_infobox_football.png")      no-repeat top right;}
.topo.fungo       {background: url("http://upload.wikimedia.org/wikipedia/commons/7/79/Picto_infobox_fungus.png")        no-repeat top right;}
.topo.rodovia     {background: url("http://upload.wikimedia.org/wikipedia/commons/5/57/Picto_infobox_motorway.png")      no-repeat top right;}
.topo.fisica      {background: url("http://upload.wikimedia.org/wikipedia/commons/d/d1/Picto_infobox_physics.png")       no-repeat top right;}
.topo.planta      {background: url("http://upload.wikimedia.org/wikipedia/commons/0/0b/Picto_infobox_plant.png")         no-repeat top right;}
.topo.estrela     {background: url("http://upload.wikimedia.org/wikipedia/commons/2/2e/Picto_infobox_star.png")          no-repeat top right;}
.topo.ferramentas {background: url("http://upload.wikimedia.org/wikipedia/commons/c/cb/Picto_infobox_tools.png")         no-repeat top right;}
.topo.virus       {background: url("http://upload.wikimedia.org/wikipedia/commons/d/dc/Picto_infobox_virus.png")         no-repeat top right;}
.topo.jornal      {background: url("http://upload.wikimedia.org/wikipedia/commons/d/d6/Picto_infobox_newspaper.png")     no-repeat top right;}
.topo.livro       {background: url("http://upload.wikimedia.org/wikipedia/commons/4/42/Picto_infobox_book.png")          no-repeat center right;}
.topo.novela      {background: url("http://upload.wikimedia.org/wikipedia/commons/4/44/Picto_infobox_TV-icon-novela.png") no-repeat center right;}
.topo.televisao   {background: url("http://upload.wikimedia.org/wikipedia/commons/a/a6/Picto_infobox_TV-T%26PC.png")     no-repeat top right;}
.topo.televisao2  {background: url("http://upload.wikimedia.org/wikipedia/commons/a/a6/Picto_infobox_TV-T%26PC.png")     no-repeat bottom right;}
.topo.computador  {background: url("http://upload.wikimedia.org/wikipedia/commons/d/d1/Picto_infobox_pc.png")            no-repeat top right;}
.topo.gnulinux    {background: url("http://upload.wikimedia.org/wikipedia/commons/a/a4/Picto_infobox_gnulinux.png")      no-repeat top right;}
.topo.internet    {background: url("http://upload.wikimedia.org/wikipedia/commons/a/a1/Picto_infobox_internet.png")      no-repeat top right;}
.topo.empresa     {background: url("http://upload.wikimedia.org/wikipedia/commons/f/ff/Picto_infobox_enterprise.png")    no-repeat top right;}
.topo.brinquedo   {background: url("http://upload.wikimedia.org/wikipedia/commons/7/74/Picto_infobox_toys.png")          no-repeat top right;}
.topo.tabuleiro   {background: url("http://upload.wikimedia.org/wikipedia/commons/2/20/Picto_infobox_board_game.png")    no-repeat top right;}
.topo.uva         {background: url("http://upload.wikimedia.org/wikipedia/commons/6/66/Picto_info_grape.png")            no-repeat top right;}
.topo.espacial    {background: url("http://upload.wikimedia.org/wikipedia/commons/9/94/Picto_infobox_shuttle.png")       no-repeat top right;}
.topo.rka         {background: url("http://upload.wikimedia.org/wikipedia/commons/1/1b/Picto_infobox_RKA.png")           no-repeat top right;}
.topo.ginastica   {background: url("http://upload.wikimedia.org/wikipedia/commons/9/92/Picto_infobox_gymnastic.png")     no-repeat top right;}
.topo.bio         {background: url("http://upload.wikimedia.org/wikipedia/commons/3/3d/Picto_infobox_bio.png")           no-repeat top right;}
.topo.maravilhas  {background: url("http://upload.wikimedia.org/wikipedia/commons/d/da/7Wonders.png")                    no-repeat top right;}
.topo.software    {background: url("http://upload.wikimedia.org/wikipedia/commons/f/fe/Picto_infobox_software.png")      no-repeat top right;}
.topo.robo        {background: url("http://upload.wikimedia.org/wikipedia/commons/5/5f/Picto_infobox_robot.png")         no-repeat top right;}

.midia.audio {background: url("http://upload.wikimedia.org/wikipedia/commons/thumb/a/a6/Gnome-speakernotes.png/35px-Gnome-speakernotes.png") no-repeat top left;} 
.midia.video {background: url("http://upload.wikimedia.org/wikipedia/en/thumb/2/20/Tango-video-x-generic.png/35px-Tango-video-x-generic.png") no-repeat top left;}

/* Fim da fase de teste da Infobox V2 */

/* Permite limitar a quantidade de niveis num indice;
   <div class="toclimit-3">, por exemplo, limitara somente
   a ==nivel 2== e ===nivel 3=== e nada inferior, contanto
   que não exista =nivel 1= na pagina.
 */
.toclimit-2 .toclevel-2,
.toclimit-3 .toclevel-3,
.toclimit-4 .toclevel-4,
.toclimit-5 .toclevel-5,
.toclimit-6 .toclevel-6,
.toclimit-7 .toclevel-7 { display: none; }
/* Remove bordas brancas de thumbnails */
div.thumb {
    border: none;
}
div.tright {
    border: none;
    margin: 0.5em 0 0.8em 1.4em;
}
div.tleft {
    border: none;
    margin: 0.5em 1.4em 0.8em 0;
}

// </source>