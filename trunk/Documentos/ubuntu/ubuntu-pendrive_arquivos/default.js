function print_toolbar () {
/*	document.write('<form class="search_form" action="http://www.google.com/search" method="get">');
	document.write('<input type="hidden" name="sitesearch" value="www.guiadohardware.net">');
	document.write('<input class="search_buttom" type="submit" value="Busca" name="submit">');
	document.write('<input class="search_query" type="text" name="q" size="10">');
	document.write('</font>');*/
	document.write('[ <a href="/index.php">HOME</a> |  <a href="/rss.html">RSS</a> | <a href="/equipe.html">Equipe</a> | <a href="/busca">Busca</a> ]');
}

function print_footer () {
	document.write('[ <a href="/index.php">HOME</a> ]');
}

function navformc () {
        nurl = document.navform.navcont.options[document.navform.navcont.selectedIndex].value;
        if (nurl.length != 0) {
                location.href = nurl;
        }
}

