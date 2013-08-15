$(document).ready( function() {

    /*
	 * Visualiza��o de respostas dos coment�rios em �rvore
	 */


	$('#listaDeComentarios a.respostas').live("click", function() {
		$(this).parent().parent().find('div.respostas').slideToggle();

		return false;
	});


	/*
	 * Exibi��o do formul�rio de resposta de coment�rio
	 */


	$('#listaDeComentarios a.responder').live("click", function() {
		$(this).parent().parent().find('.espacoResposta').append($('.formComentario')).hide().fadeIn();

		$('.formComentario .titulo h3').html('Responder coment�rio');
		$('.formComentario .submit').attr('value', 'Enviar resposta');
		$('.formComentario input[name="codComentarioAnterior"]').val($(this).attr('rel'));

		//alert($(window).height());
		$('html, body').animate({
			scrollTop: ($('.formComentario .submit').offset().top - $(window).height() + 45)
		}, 500, function() {
			if($('.formComentario input[name="indStatusLogin"]').val() == '0') {
				$('.formComentario input[name="strEmailComentario"]').focus();
			}
		});
		return false;
	});


	/*
	 * A��o do cancelamento do formul�rio de resposta de coment�rio
	 */


	$('.formComentario a.cancelarResposta').live("click", function() {

		if($('.formComentario input[name="codComentarioAnterior"]').val() != '') {
			$('#blocoComentario').append($('#listaDeComentarios .formComentario')).hide().fadeIn();
		}

		$('.formComentario .titulo h3').html('O que voc� achou deste artigo?');
		$('.formComentario .submit').attr('value', 'Enviar coment�rio');
		$('.formComentario input[name="codComentarioAnterior"]').val('');

		return false;
	});


	/*
	 * Aplica��o dos labels dos campos "T�tulo" e "Coment�rio" dentro dos pr�prios campos
	 */


	var $strTitulo = $('.formComentario .strTitulo');
	var $strComentario = $('.formComentario .strComentario');

	// T�tulo interno dos campos de coment�rio

    if($strTitulo.val() == '' || $strTitulo.val() == 'T�tulo') {
        $strTitulo.addClass('vazio').val('T�tulo');
    }
    $strTitulo.focus(function() {
        if($strTitulo.hasClass('vazio')) {
            $strTitulo.removeClass('vazio').val('');
        }
    });
    $strTitulo.blur(function() {
        if($strTitulo.val() == '') {
            $strTitulo.addClass('vazio').val('T�tulo');
        }
    });
    if($strComentario.val() == '' || $strComentario.val() == 'Mensagem') {
        $strComentario.addClass('vazio').val('Mensagem');
    }
    $strComentario.focus(function() {
        if($strComentario.hasClass('vazio')) {
            $strComentario.removeClass('vazio').val('');
        }
    });
    $strComentario.blur(function() {
        if($strComentario.val() == '') {
            $strComentario.addClass('vazio').val('Mensagem');
        }
    });


	/*
	 * A��o de login dentro do formul�rio de coment�rio
	 */


	function fazerLogin() {
		if($('.formComentario input[name="strEmailComentario"]').val() != '' && $('.formComentario input[name="strSenhaComentario"]').val() != '' && $('.formComentario input[name="indStatusLogin"]').val() == '0') {
			$('.formComentario .status').removeClass('alerta').addClass('carregando').html('');

			$.ajax({
				type: "POST",
				url: "/ajax_login.php",
				data: {'ajax': 1, 'strEmail': $('.formComentario input[name="strEmailComentario"]').val(), 'strSenha': $('.formComentario input[name="strSenhaComentario"]').val(), 'indLogin': 1},
				dataType: 'json',
				success: function(data){
					if(data['estaLogado'] == true) {
						$('.formComentario input[name="indStatusLogin"]').val('1');
						$('.formComentario .avisoLogin').hide();
						$('.formComentario .status').removeClass('carregando').removeClass('alerta').html('');
						$('.formComentario .login').hide().html('<div class="status externo"></div><div class="dados">Usu�rio<br /><strong>'+ data['nome']+'</strong></div><div class="dados">E-mail:<br />'+data['email']+'</div>').fadeIn();
					} else {
						$('.formComentario input[name="indStatusLogin"]').val('0');

						if(data['erro'] == 'dadosIncorretos')
						{
							$('.formComentario .status').removeClass('carregando').addClass('alerta').html('Os dados est�o incorretos.');
						}
						else if(data['erro'] == 'semCadastro')
						{
							$('.formComentario .status').removeClass('carregando').addClass('alerta').html('E-mail n�o cadastrado. <a href="/cadastro/" class="cadastrar">Cadastrar</a>?');
						}
						else if(data['erro'] == 'emailInvalido')
						{
							$('.formComentario .status').removeClass('carregando').addClass('alerta').html('E-mail inv�lido.');
						}
					}
				}
			});
		}
	}

	$('.formComentario input[name="strEmailComentario"], .formComentario input[name="strSenhaComentario"]').change(fazerLogin);


	/*
	 * Envio do coment�rio
	 */

	$('#formComentario').live("submit", function() {
		if($('.formComentario input[name="indStatusLogin"]').val() == '0') {
			$('.formComentario .status').removeClass('carregando').addClass('alerta').html('Dados obrigat�rios.');
			$('.formComentario input[name="strEmailComentario"]').focus();
			return false;
		}

        if($strTitulo.hasClass('vazio') || $strComentario.hasClass('vazio')) {
            $('.formComentario .status').removeClass('carregando').addClass('alerta').html('T�tulo e mensagem s�o obrigat�rios.');
            return false;
        }

        $('#formComentario .submit').attr('disabled', true);

		$.ajax({
			type: "POST",
			url: $(this).attr("action"),
			data: $(this).serialize()+"&ajax=1",
            dataType: 'json',
			success: function(data) {
				atualizarComentarios(data['htmlComentarios']);
                $('#comment-'+data['codComentario']).hide().fadeIn('slow');
			}
		});
		return false;
	});

    function atualizarComentarios(data) {
        $('#comentarios').html(data);
        //atualizarTituloInternoCamposComentario();
    }

});