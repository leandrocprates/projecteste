/*	$Id: overlay.js,v 1.9 2009/05/06 14:48:44 mbaierl Exp $ */
/* Documentation at https://w3.tap.ibm.com/w3ki04/display/cwt/overlay.js */
(function(B){var A={loadingDimensions:false,useMask:false,close:function(C){var D=B(C);while(D.hasClass("ibm-common-overlay")===false){D=D.parent()}A.hide(D);return false},getMask:function(D){var C=D.get(0);if(typeof C.overlaymask==="undefined"){C.overlaymask=B('<iframe border="0" class="ibm-common-overlay-mask" src="//www.ibm.com/common/stats/sa_data.html" />');
C.overlaymask.get(0).frameBorder="0";D.after(C.overlaymask)}return C.overlaymask},hide:function(C){var D=C instanceof jQuery?C:typeof C==="string"?B("#"+C):C;if(A.useMask){A.getMask(D).hide()}D.fadeOut("fast");if(D.get(0).trigger){D.get(0).trigger.focus()}},init:function(){var C;if(B.browser.msie){C=parseFloat(B.browser.version);if(!isNaN(C)&&C<7){A.useMask=true}}},innerHeight:function(){var C;if(window.innerHeight){C=window.innerHeight}else{if(document.documentElement.clientHeight&&document.documentElement.clientHeight>0){C=document.documentElement.clientHeight
}else{C=document.body.clientHeight}}return C},scrollTop:function(){var C=0;if(document.documentElement.scrollTop!==0){C=document.documentElement.scrollTop}else{if(document.body.scrollTop!==0){C=document.body.scrollTop}}return C},setPosition:function(I){var H=B("#ibm-content").offset(),G=A.innerHeight(),D=B(window),E=A.scrollTop(),C=D.width(),F={};if(I.height()>G){H.top=E-H.top+"px"}else{H.top=parseInt((G-I.height())/2,10)+E-H.top+"px"}if(ibmCommon.meta.cc=="il"){H.left=parseInt((C-I.width())/2,10)+"px"
}else{H.left=parseInt((C-I.width())/2,10)-H.left+"px"}I.css(H);if(A.useMask){A.getMask(I).css(H).height(I.height()-17).width(I.width());A.getMask(I).show()}},show:function(C,D){var E=C instanceof jQuery?C:typeof C==="string"?B("#"+C):C;E.fadeIn("fast");A.setPosition(E);E.find("a.ibm-access:first").focus();if(D&&E.get(0)){E.get(0).trigger=D}return false}};window.ibmCommon.Overlays=A;B(function(){B(".ibm-common-overlay a.ibm-common-overlay-close").click(function(){return A.close(this)});A.init()})})(jQuery);