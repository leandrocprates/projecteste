
Event.KEY_SHIFT = 16;
Event.KEY_END 	= 35;
Event.KEY_HOME 	= 36;

var teclasEspeciais = new Array(
	Event.KEY_BACKSPACE,	// 08 - Backspace
	Event.KEY_TAB, 			// 09 - Tab
	Event.KEY_RETURN, 		// 13 - Enter
	Event.KEY_SHIFT,		// 16 - Shift
	Event.KEY_ESC,			// 27 - Esc
	Event.KEY_END, 			// 35 - End
	Event.KEY_HOME, 		// 36 - Home
	Event.KEY_LEFT, 		// 37 - Seta esquerda
	Event.KEY_UP, 			// 38 - Seta para cima
	Event.KEY_RIGHT, 		// 39 - Seta direita
	Event.KEY_DOWN, 		// 40 - Seta abaixo
	Event.KEY_DELETE  		// 46 - Delete
);


function buscarDados(elem, ctx) {

	var handlerFunc = function(t) {
    	pessoa = eval('(' + t.responseText + ')');
    	elements = $A(Form.getElements(elem.form));
    	elements.each(
    		function(e) {
    			if (e.type != 'button' && e.type != 'submit' && e.name != 'evento') {
    				if (e.type == 'radio') {
    					if (pessoa[e.name] == 'M')
    						$('m').checked = true;
    					else
    						$('f').checked = true;
    				} else {
						e.value = pessoa[e.id] == null ? '' : pessoa[e.id];
					}
				}
    		}
    	);
	}

	ajax = new Ajax.Request(ctx + '/buscaCpf', 
		{
			method: 'get',
			parameters: 'cpf=' + elem.value, 
			onSuccess: handlerFunc 
		}
	);
}


function formatarMascara(src, event, mask) {
	var i;
	
	if (document.selection) // Internet Explorer
		i = Math.abs(document.selection.createRange().moveStart("character", -1000000));
	else // Firefox
		i = src.selectionStart;
	
	var saida = mask.substring(0,1);
	var texto = mask.substring(i);	
	var rcode = event.which ? event.which : event.keyCode;

	// Enter, backspace, delete e setas direcionais
	if (teclasEspeciais.indexOf(rcode) != -1) {
		return true;
	}

	if (rcode >= 48 && rcode <= 57) {
		if (texto.substring(0,1) != saida)
			src.value = src.value.substring(0,i) + texto.substring(0,1) + src.value.substring(i);
		return true;
	} else {
		return false;
	}
}

function formataData(src, event) {
	return formatarMascara(src, event, '##/##/####');
}

function formataCpf(src, event) {
	return formatarMascara(src, event, '###.###.###-##');
}