jQuery(document).ready(function(A){login="false";userid="";whichTags="init";pCont="";mCont="";signInMCont="";accessCont="";pValue=0;mValue=0;zoneHash=new Object();zoneHash.aix="AIX and UNIX zone";zoneHash.data="Information Management zone";zoneHash.lotus="Lotus zone";zoneHash.rational="Rational zone";zoneHash.tivoli="Tivoli zone";zoneHash.websphere="WebSphere zone";zoneHash.architecture="Architecture zone";zoneHash.autonomic="Autonomic computing zone";zoneHash.java="Java technology zone";zoneHash.library="Technical library";
zoneHash.linux="Linux zone";zoneHash.opensource="Open source zone";zoneHash.power="Multicore acceleration zone";zoneHash.webservices="SOA and Web services zone";zoneHash.web="Web development zone";zoneHash.xml="XML zone";zoneHash.wireless="Wireless technology zone";A.getPopularTags("/developerworks/dwtags/dwjquerytabtags?lang=en&base="+A.getZoneUrl(location.href));A.getUserTags();A.getTagsForContent("/developerworks/tagging/UseCaseServlet?format=maverick&use_case=geturltags&action=gettags&url="+location.href)
});function popupform(B,A){if(!window.focus){return true}window.open("",A,"height=570,width=760,scrollbars=yes,resizable=yes");B.target=A;return true}function launchTagWindow(B){var A=jQuery.getZone(location.href);A=zoneHash[A];if((A!=null)&&(A!=undefined)){B=B+"&base="+jQuery.getZoneUrl(location.href)+"&dwapp="+A}else{B=B+"&base="+jQuery.getZoneUrl(location.href)}windowObject=window.open(B,"TagWindow","height=570,width=760,scrollbars=yes,resizable=1");windowObject.focus()}(function(A){jQuery.extend({launchTagThisWindow:function(){var B="/developerworks/mydeveloperworks/bookmarks/bookmarklet/dwtagg/dwtagpost.jsp?url="+encodeURIComponent(jQuery.normalizeUrl(location.href))+"&title="+encodeURIComponent(window.document.title);
if(login=="false"){windowObject=window.open(B,"Tagit","height=570,width=600,scrollbars=yes,resizable=1")}else{windowObject=window.open(B,"Tagit","height=570,width=600,scrollbars=false,resizable=1")}windowObject.focus()}})})(jQuery);(function(A){jQuery.extend({prepAccessDiv:function(){if((pCont!="")&&(mCont!="")){var C=jQuery.getListItems(pCont);var B="";if(signInMCont==""){B=jQuery.getListItems(mCont)}else{B=signInMCont}accessCont='<div id="dw-tag-access" class="ibm-access"><h2>Popular article tags</h2>'+C+"<p>End of Popular article tags</p><h2>My article tags</h2>"+B+"<p>End of My article tags</p></div>";
A(accessCont).insertAfter("#dw-tag-select-my")}}})})(jQuery);(function(A){jQuery.extend({getListItems:function(E){var C="<ul>";var D="</ul>";var B=E.indexOf(C);if(B!=-1){E=E.substring(B);var F=E.indexOf(D);if(F!=-1){F=F+D.length;E=E.substring(0,F)}}return E}})})(jQuery);(function(A){jQuery.extend({normalizeUrl:function(C){if(C==null||C==undefined){C=location.href}var B=C.indexOf("#");if(B!=-1){C=C.substring(0,B)}C=C.replace(/https:/,"http:");B=C.indexOf("/developerworks/spaces/");if(B!=-1){var D=C.indexOf("?");
if(D>B){C=C.substring(0,D);return C}}B=C.indexOf("&start");if(B!=-1){C=C.substring(0,B)}B=C.indexOf("&tstart");if(B!=-1){C=C.substring(0,B)}return C}})})(jQuery);(function(A){jQuery.extend({getWIInfo:function(){var B="false";jQuery.ajax({type:"GET",url:"/developerworks/dwwi/jsp/Auth.jsp?format=json",dataType:"json",success:function(C){if(C&&C.status=="false"){login="false";userid=null;B="false"}else{if(C&&C.status=="true"){login="true";userid=C.ibmuniqueid;B="true"}}},failure:function(C){login="false";
userid=null;alert("onFail: "+C.statusText)},async:false});return B}})})(jQuery);(function(A){jQuery.extend({handleSlider:function(F,D){var E=0;currValue=D.value;if((whichTags=="init")||(whichTags=="pTags")){E=pValue}if(whichTags=="mTags"){E=mValue}if(E<currValue){for(var C=E;C<currValue;C++){A("a.lotusF"+(C+1)).addClass("dw-hidetag")}if((whichTags=="init")||(whichTags=="pTags")){pValue=currValue}if(whichTags=="mTags"){mValue=currValue}}if(E>currValue){for(var B=currValue;B<E;B++){A("a.lotusF"+(B+1)).removeClass("dw-hidetag")
}if((whichTags=="init")||(whichTags=="pTags")){pValue=currValue}if(whichTags=="mTags"){mValue=currValue}}}})})(jQuery);(function(A){jQuery.extend({getZoneUrl:function(E){if(E==null||E==undefined){E=location.href}else{var C="/developerworks/";var G=C.length;var D=E.indexOf(C);if(D!=-1){D=D+G;var B=E.substring(D);var F=B.substring(0,D).indexOf("/");if(F!=-1){E=E.substring(0,(D+F))}else{E=location.href}}else{E=location.href}}return E}})})(jQuery);(function(A){jQuery.extend({getZone:function(E){if(E==null||E==undefined){E=""
}else{var C="/developerworks/";var G=C.length;var D=E.indexOf(C);if(D!=-1){D=D+G;var B=E.substring(D);var F=B.substring(0,D).indexOf("/");if(F!=-1){E=B.substring(0,F)}else{E=""}}else{E=""}}return E}})})(jQuery);(function(A){jQuery.extend({showUserTags:function(){var B=jQuery.getWIInfo();if(login=="true"){pCont=jQuery("#dw-tag-cloud").html();jQuery("#dw-tag-cloud").html('<center><img class="loading" src="/developerworks/mydeveloperworks/bookmarks/h3/images/progressIndicator.gif" alt="Loading Content" height="21" width="21"/></center>');
jQuery("#dw-tag-cloud").html(mCont);jQuery("#content-slider").html("");jQuery("#content-slider").slider({animate:true,min:0,max:4,step:1,slide:function C(E,D){jQuery.handleSlider(E,D)}});jQuery("#dw-tag-select-popular").addClass("dw-hidetag");jQuery("#dw-tag-select-my").removeClass("dw-hidetag");jQuery("#acloud").click(function(){jQuery.switchVisible("#dogearTagList","#dogearTagCloud")});jQuery("#alist").click(function(){jQuery.switchVisible("#dogearTagCloud","#dogearTagList")});if(whichTags=="init"){whichTags="mTags";
jQuery("#a-popular").click(function(){jQuery.showAlternateTags()})}else{if(whichTags=="pTags"){whichTags="mTags";A("#content-slider").slider("option","value",mValue)}else{}}}else{pCont=jQuery("#dw-tag-cloud").html();jQuery("#dw-tag-select-popular").addClass("dw-hidetag");jQuery("#dw-tag-select-my").removeClass("dw-hidetag");jQuery("#dw-tag-cloud").html(mCont);if(whichTags=="init"){jQuery("#a-popular").click(function(){jQuery.showAlternateTags()})}whichTags="mTags"}}})})(jQuery);(function(A){jQuery.extend({showAlternateTags:function(){if(whichTags=="init"){jQuery.showUserTags()
}else{if(whichTags=="mTags"){whichTags="pTags";mCont=jQuery("#dw-tag-cloud").html();jQuery("#dw-tag-cloud").html(pCont);jQuery("#content-slider").html("");jQuery("#content-slider").slider({animate:true,min:0,max:4,step:1,slide:function B(D,C){jQuery.handleSlider(D,C)}});A("#content-slider").slider("option","value",pValue);jQuery("#dw-tag-select-my").addClass("dw-hidetag");jQuery("#dw-tag-select-popular").removeClass("dw-hidetag");jQuery("#acloud").click(function(){jQuery.switchVisible("#dogearTagList","#dogearTagCloud")
});jQuery("#alist").click(function(){jQuery.switchVisible("#dogearTagCloud","#dogearTagList")})}else{if(whichTags=="pTags"){jQuery.showUserTags()}else{}}}}})})(jQuery);(function(A){jQuery.extend({switchVisible:function(C,B){if(C!=""){jQuery(C).addClass("dw-hidetag")}if(B!=""){jQuery(B).removeClass("dw-hidetag")}}})})(jQuery);(function(A){jQuery.extend({getPopularTags:function(B){jQuery.ajax({type:"GET",url:B,dataType:"text",success:function(C){C=jQuery.trim(C);if(C.length==0){jQuery("#dw-tag-cloud").html("<center>No active tags</center><br />");
pCont="<center>No active tags</center><br />"}else{jQuery("#dw-tag-cloud").html(C);pCont=C}jQuery.prepAccessDiv();jQuery("#acloud").click(function(){jQuery.switchVisible("#dogearTagList","#dogearTagCloud")});jQuery("#alist").click(function(){jQuery.switchVisible("#dogearTagCloud","#dogearTagList")});jQuery("#a-my").click(function(){jQuery.showAlternateTags()});jQuery.switchVisible("","#dw-tag-cloud-container");jQuery("#content-slider").slider({animate:true,min:0,max:4,step:1,slide:function D(F,E){jQuery.handleSlider(F,E)
}})},async:true})}})})(jQuery);(function(A){jQuery.extend({getUserTags:function(){var B=jQuery.getWIInfo();urlStr="/developerworks/dwtags/dwjquerytabtags?userid="+userid+"&base="+jQuery.getZoneUrl(location.href)+"&lang=en";if(login=="true"){jQuery.ajax({type:"GET",url:urlStr,dataType:"text",success:function(C){C=jQuery.trim(C);if(C.length==0){mCont="<center>No active tags</center><br />"}else{mCont=C}jQuery.prepAccessDiv()},async:true})}else{mCont='<center>Please <a href="/developerworks/dwwi/DWAuthRouter?m=auth&d='+encodeURIComponent(location.href)+'">sign in</a> to access<br />My Tags</center><br />';
signInMCont='<div id="dw-tag-access-my" class="ibm-access"><center>To access My Tags, please <a href="/developerworks/dwwi/DWAuthRouter?m=auth&d='+encodeURIComponent(location.href)+'">sign in</a><p>Read Popular tags</p></center><br /></div>';jQuery.prepAccessDiv()}}})})(jQuery);(function(A){jQuery.extend({getTagsForContent:function(B){jQuery.ajax({url:B,dataType:"html",success:function(D){D=jQuery.trim(D);jQuery("#dw-tag-content").html(D);var E=jQuery("#moretags").html();if(E!=null){var C=E.indexOf("<A");
if(C==-1){C=E.indexOf("<a")}if(C!=-1){E=E.substring(C);jQuery("#dw-moretags-access").html(E)}}jQuery("a.dwmoretags").cluetip({local:true,showTitle:false,positionBy:"bottomTop",sticky:true,mouseOutClose:true,closeText:'<img src="//www.ibm.com/developerworks/js/jquery/cluetip98/i/x.gif" alt="Close" />',arrows:false,dropShadow:true,cluetipClass:"dwbasic"})},async:true})}})})(jQuery);