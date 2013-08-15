/* <source lang="css"> */

 #siteNotice { padding-left: 4px; } /* MW:Sitenotice */
 #fundraising { font-style: italic; } /* MW:Sitenotice (manual) */

 #siteSub {          /* Adiciona o texto "Origem: Wikipédia, a enciclopédia livre." sob o título do artigo */
    display: inline;
    font-size: 90%;
    font-weight: normal;
 }
 #bodyContent #siteSub a {
    color: #000;
    text-decoration: none;
    background-color: transparent;
    background-image: none;
    padding-right: 0;
 }

 /* lista de caracteres especiais funciona melhor sem sublinhado */
 #editpage-specialchars a { text-decoration: none; }
 #editpage-specialchars a:hover { text-decoration: underline; }

 #pt-login {
   font-weight: bold;
   font-size: 110%;
 }

 /* Cor de fundo das páginas  */
/* Make all non-namespace pages have a light blue content area. This is done by
        setting the background color for all #content areas to light blue and then
        overriding it for any #content enclosed in a .ns-0 (main namespace). I then
        do the same for the "tab" background colors. --Lupo */

#content,
#mytabs li.selected a,
#p-cactions li.selected a,
#mytabs li a,
#p-cactions li a,
#p-cactions li a:hover {
  background-color: #F8FCFF; /* alternativa: #F3F3FF */
}
.ns-0 #content,
.ns-0 #mytabs li.selected a,
.ns-0 #p-cactions li.selected a,
.ns-0 #mytabs li a,
.ns-0 #p-cactions li a,
.ns-0 #p-cactions li a:hover {
  background-color: white;
}
.ns-102 * #content,
.ns-102 * #p-cactions li,
.ns-102 * #p-cactions li a { background:#FFF }
.ns--1 table,
.ns-2 table,
.ns-3 table,
.ns-4 table,
.ns-6 table,
.ns--1 form {
  background: inherit;
}

 /* Ícones posicionado no canto superior  */

 /*
 ** Geocoordenadas
 */
#coordinates {  
    position: absolute;
    z-index: 1;
    border: none;
    background: none;
    right: 30px;
    top: 4.8em;
    float: right;
    margin: 0.0em;
    padding: 0.0em;
    line-height: 1.5em;
    text-align: right;
    text-indent: 0;
    font-size: 85%;
    text-transform: none;
    white-space: nowrap;
}
 
#coordinates a[href ^="http://"] {
  background: url(http://upload.wikimedia.org/wikipedia/de/d/d4/Gnome-globe.png) center right no-repeat !important;
  padding-right: 18px !important;
}



 /*
 ** Artigos protegidos
 */
#protegida{position:absolute;z-index:100;right:10px;top:50px;}

 /*
 ** FIST
 */
#FIST1 {position:absolute; z-index:100; right:10px; top:10px;}

 /*
 ** Artigo Destacado
 */
#destaques1 {position: absolute;z-index: 1;border: none;right: 10px;top:15px;margin: 0.0em;padding: 0.0em;}

 /*
 ** atalho
 */
#atalho {
  position: absolute;
  z-index: 1;
  border:1px solid #999;
  background:#fff;
  right: 15px; 
  top: 15px;
  width: 95px;
  margin:0 0 .5em 1em;
  padding: 0.0em;
  line-height: 1.5em;
  text-align: center;
  text-indent: 0;
  font-size: 85%;
  text-transform: none;
  white-space: normal;
}


 /* Pequenos ajustes */
/*
** Fundo dos elementos na página principal
** (a utilizar esta class, claro)
*/
.MainPageBG {
  background-color: transparent;
}
/* Mudanças recentes (RC), link de edição */
#rc-elnk {
  font-size: 94%;
  background-color: #fcfcfc;
  border: 1px dotted #006699;
  padding: 0.1em 0.3em;
  position: absolute;
  float: right;
  top: 0.4em;
  right: 0.4em;
  left: auto;
  text-transform: none;
}
html>body #rc-elnk {
  border: thin dotted #006699;
}
#rc-elnk .rc-esc {
  display: none;
}

/*
 * Em especial para a [[Predefinição:Ref]]
 */
.plainlinksneverexpand {
  background: none !important;
  padding: 0 !important;
}

.plainlinksneverexpand .urlexpansion {
  display: none !important;
}

/* Make sure that ext links displayed within "plainlinksneverexpand" don't get
   the arrow...
*/
#bodyContent .plainlinksneverexpand a {
   background: none !important;
   padding: 0 !important
}

 /* try adding here, this had no effect in [[MediaWiki:Common.css]] */
 .plainlinksneverexpand a.external.text:after {
  display: none !important
 }


/* Wikipedia:Cartografia dos Wikipedistas */
div.PontoMapa
{
 position:absolute;
 width:1px;
 height:1px;
 background:#000000;
 border: 1px solid #FFFFFF;    
}


 /* media: print */
@media print {
  /* Do not print edit link in templates using Template:Ed
     Do not print certain classes that shouldn't appear on paper */
  .editlink, .noprint, .metadata, .dablink { display: none }

  #bodyContent a[href ^="http://"] {
      background: none;
      padding-right: 0;
  }
}

@media screen, handheld, projection {
    cite *.printonly {
        display: none;
    }
}

.page-Especial_Recentchanges ul.special li { white-space: nowrap; } 


 /* MediaWiki:Edittools */

/* extra buttons for edit dialog (from tr:) */
.my-buttons {
   padding: .5em;
}
.my-buttons a {
   color: black;
   background-color: #cde !important;
   font-weight: bold;
   font-size: .9em;
   text-decoration: none;
   border: thin #069 outset;
   padding: 0 .1em .1em;
}
.my-buttons a:hover, .my-buttons a:active {
   background-color: #bcd;
   border-style: inset;
}

/* </source> */