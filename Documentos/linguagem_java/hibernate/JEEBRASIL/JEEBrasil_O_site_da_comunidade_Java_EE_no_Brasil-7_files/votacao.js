
var media;
var notaUsuario;
var xmlHttpRequest;

function votar(idPublicacao, nota, ctx) {
	var url = ctx + "/votar?idPublicacao="+idPublicacao+"&nota="+nota;
	notaUsuario = nota;
	retrieveURL(url, getNota);
}

function retrieveURL(url, funcao) {

	if (window.XMLHttpRequest) { // Non-IE browsers
		xmlHttpRequest = new XMLHttpRequest();
		xmlHttpRequest.onreadystatechange = funcao;
		
		try {
			xmlHttpRequest.open("GET", url, true);
		} catch (e) {
			alert(e);
		}
		
		xmlHttpRequest.send(null);
		
	} else if (window.ActiveXObject) { // IE
		xmlHttpRequest = new ActiveXObject("Microsoft.XMLHTTP");

		if (xmlHttpRequest) {
			xmlHttpRequest.onreadystatechange = funcao;
			xmlHttpRequest.open("GET", url, true);
			xmlHttpRequest.send();
		}
	}

	return xmlHttpRequest;
}

function getNota() {

	if (xmlHttpRequest != null && xmlHttpRequest.readyState == 4) {
		if (xmlHttpRequest.status == 200) {
			media = xmlHttpRequest.responseText;
			$('current-rating').style.width = media + 'px';
			$('voting').innerHTML = '<li class="current-rating" id="current-rating" style="width: '+media+'px">Currently '+media+'/5 Stars.</li>';
			$('user-note').innerHTML = 'Sua Nota: ' + notaUsuario;
		}
	}
}