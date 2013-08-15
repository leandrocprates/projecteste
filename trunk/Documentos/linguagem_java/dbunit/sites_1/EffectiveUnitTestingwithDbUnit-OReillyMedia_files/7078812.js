if(document.createStyleSheet)
        {
            document.createStyleSheet('http://api.aggregateknowledge.com/2007/01/15/css');
        } else {
            var styles = "@import url(' http://api.aggregateknowledge.com/2007/01/15/css ');";
            var akStylesheet = document.createElement('link');
            akStylesheet.rel = 'stylesheet';
            akStylesheet.href = 'data:text/css,' + escape(styles);
            document.getElementsByTagName('head')[0].appendChild(akStylesheet);
        }
function execScripts(documentElement) {
var scriptElements = documentElement.getElementsByTagName('script'); 
var scriptElementsCount = scriptElements.length;
for (var i = scriptElementsCount-1; i >= 0;i--){
var scriptElement = scriptElements[i]; 
var agkn = scriptElement.getAttribute("agkn");
if (agkn == 'agkn' && scriptElement.id != 'akfooterscript'){
if (scriptElement.innerHTML != '')
eval(scriptElement.innerHTML);
else {
var createdScriptElement = document.createElement('script');
createdScriptElement.src = scriptElement.src;
createdScriptElement.type = 'text/javascript';
if(scriptElement.parentNode != null)
scriptElement.parentNode.removeChild(scriptElement);
documentElement.appendChild(createdScriptElement); 
}}else if (agkn == 'agkn' && scriptElement.id == 'akfooterscript'){
if(scriptElement.parentNode != null)
scriptElement.parentNode.removeChild(scriptElement);
}}};

if (!window.ak) var ak = function() {};
ak.getAKContent = function() {
return '<!--\r\n'
+ '    <link rel="stylesheet" HREF="http://api.aggregateknowledge.com/2007/01/15/css" TYPE="text/css" MEDIA=screen>\r\n'
+ '-->\r\n'
+ '    <scr' + 'ipt agkn=\'agkn\' type = "text/javascript" id = "akheaderscript">\r\n'
+ '        if(document.createStyleSheet)\r\n'
+ '        {\r\n'
+ '            document.createStyleSheet(\'http://api.aggregateknowledge.com/2007/01/15/css\');\r\n'
+ '        } else {\r\n'
+ '            var styles = "@import url(\' http://api.aggregateknowledge.com/2007/01/15/css \');";\r\n'
+ '            var akStylesheet = document.createElement(\'link\');\r\n'
+ '            akStylesheet.rel = \'stylesheet\';\r\n'
+ '            akStylesheet.href = \'data:text/css,\' + escape(styles);\r\n'
+ '            document.getElementsByTagName(\'head\')[0].appendChild(akStylesheet);\r\n'
+ '        }\r\n'
+ '    </scr' + 'ipt>\r\n'
+ '<table>\r\n'
+ '	<tr>\r\n'
+ '		<td>\r\n'
+ '			<div class="sidebar-item">\r\n'
+ '				<h3>Recommended for You</h3>\r\n'
+ '				<div class="sidebar-item-content" style="text-align: center">\r\n'
+ '                        				                        <p>\r\n'
+ '		                        	<a href="http://api.aggregateknowledge.com/cp?t=training.oreilly.com%2Fandroidapps%2F%3fCMP%3dAFC-ak_training%26ATT%3dO%2527Reilly%2bTraining%253A%2bDeveloping%2bAndroid%2bApplications%253A%2bBuild%252c%2bCompile%252c%2band%2bTest%2bYour%2bFirst%2bAndroid%2bApplication&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=0&s=DE&rt=RECOMMENDATION&i=443"><img src="http://oreilly.com/images/oreilly/training/icon_android.png" border="0" alt="O\'Reilly Training: Developing Android Applications: Build, Compile, and Test Your First Android Application" style="padding-bottom: 6px;" /></a>\r\n'
+ '	                        		<br />\r\n'
+ '	                        												<a href="http://api.aggregateknowledge.com/cp?t=training.oreilly.com%2Fandroidapps%2F%3fCMP%3dAFC-ak_training%26ATT%3dO%2527Reilly%2bTraining%253A%2bDeveloping%2bAndroid%2bApplications%253A%2bBuild%252c%2bCompile%252c%2band%2bTest%2bYour%2bFirst%2bAndroid%2bApplication&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=0&s=DE&rt=RECOMMENDATION&i=443"><strong>O\'Reilly Training: Developing Android Applications: Build, Compile, and Test Your First Android Application</strong></a>\r\n'
+ '										<br>\r\n'
+ '																		                        		</p>\r\n'
+ '                        		                        			<hr /> <!-- 2 -->\r\n'
+ '		                        		                        <p>\r\n'
+ '		                        	<a href="http://api.aggregateknowledge.com/cp?t=www.web2expo.com%2Fwebexny2009%2Fpublic%2Fschedule%2Fdetail%2F9864%3fCMP%3dAFC-ak_conference%26ATT%3dWeb%253AJava%2bin%2bWeb%2b2.0&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=1&s=DE&rt=RECOMMENDATION&i=443"><img src="http://assets.en.oreilly.com/1/event/31/webexny2009_logo_ak.png" border="0" alt="" style="padding-bottom: 6px;" /></a>\r\n'
+ '	                        		<br />\r\n'
+ '	                        												<a href="http://api.aggregateknowledge.com/cp?t=www.web2expo.com%2Fwebexny2009%2Fpublic%2Fschedule%2Fdetail%2F9864%3fCMP%3dAFC-ak_conference%26ATT%3dWeb%253AJava%2bin%2bWeb%2b2.0&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=1&s=DE&rt=RECOMMENDATION&i=443"><strong>Java in Web 2.0</strong></a>\r\n'
+ '																		                        		</p>\r\n'
+ '                        		                        			<hr /> <!-- 3 -->\r\n'
+ '		                        		                        <p>\r\n'
+ '		                        	<a href="http://api.aggregateknowledge.com/cp?t=oreilly.com%2Fcatalog%2F9780596002398%3fCMP%3dAFC-ak_book%26ATT%3dDreamweaver%2bin%2ba%2bNutshell%252c&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=2&s=DE&rt=RECOMMENDATION&i=443"><img src="http://covers.oreilly.com/images/9780596002398/bkt.gif" border="0" alt="Dreamweaver in a Nutshell," style="padding-bottom: 6px;" /></a>\r\n'
+ '	                        		<br />\r\n'
+ '	                        												<a href="http://api.aggregateknowledge.com/cp?t=oreilly.com%2Fcatalog%2F9780596002398%3fCMP%3dAFC-ak_book%26ATT%3dDreamweaver%2bin%2ba%2bNutshell%252c&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=2&s=DE&rt=RECOMMENDATION&i=443"><strong>Dreamweaver in a Nutshell,</strong></a>\r\n'
+ '										<br>\r\n'
+ '										 Format: Print, \r\n'
+ '																												$29.95\r\n'
+ '									                        		</p>\r\n'
+ '                        		                        			<hr /> <!-- 4 -->\r\n'
+ '		                        		                        <p>\r\n'
+ '		                        	<a href="http://api.aggregateknowledge.com/cp?t=oreilly.com%2Fcatalog%2F9780596510237%3fCMP%3dAFC-ak_book%26ATT%3dChecking%2bJava%2bPrograms%252c&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=3&s=DE&rt=RECOMMENDATION&i=443"><img src="http://covers.oreilly.com/images/9780596510237/bkt.gif" border="0" alt="Checking Java Programs," style="padding-bottom: 6px;" /></a>\r\n'
+ '	                        		<br />\r\n'
+ '	                        												<a href="http://api.aggregateknowledge.com/cp?t=oreilly.com%2Fcatalog%2F9780596510237%3fCMP%3dAFC-ak_book%26ATT%3dChecking%2bJava%2bPrograms%252c&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=3&s=DE&rt=RECOMMENDATION&i=443"><strong>Checking Java Programs,</strong></a>\r\n'
+ '										<br>\r\n'
+ '										 Format: Ebook, \r\n'
+ '																												$9.99\r\n'
+ '									                        		</p>\r\n'
+ '                        		                        			<hr /> <!-- 5 -->\r\n'
+ '		                        		                        <p>\r\n'
+ '		                        	<a href="http://api.aggregateknowledge.com/cp?t=oreilly.com%2Fcatalog%2F9780978739218%3fCMP%3dAFC-ak_book%26ATT%3dRelease%2bIt!%252c&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=4&s=DE&rt=RECOMMENDATION&i=443"><img src="http://covers.oreilly.com/images/9780978739218/bkt.gif" border="0" alt="Release It!," style="padding-bottom: 6px;" /></a>\r\n'
+ '	                        		<br />\r\n'
+ '	                        												<a href="http://api.aggregateknowledge.com/cp?t=oreilly.com%2Fcatalog%2F9780978739218%3fCMP%3dAFC-ak_book%26ATT%3dRelease%2bIt!%252c&f=www.onjava.com%2Fpub%2Fa%2Fonjava%2F2004%2F01%2F21%2Fdbunit.html&rg=979&sid=0&rid=1&a=9561&p=4&s=DE&rt=RECOMMENDATION&i=443"><strong>Release It!,</strong></a>\r\n'
+ '										<br>\r\n'
+ '										 Format: Print, \r\n'
+ '																												$34.95\r\n'
+ '									                        		</p>\r\n'
+ '																						</div>	\r\n'
+ '			</div>\r\n'
+ '		</td>\r\n'
+ '	</tr>\r\n'
+ '</table>\r\n'
+ '<scr' + 'ipt agkn=\'agkn\' type="text/javascript" id = "akfooterscript">\r\n'
+ '</scr' + 'ipt>\r\n'
+ '<scr' + 'ipt agkn=\'agkn\' type="text/javascript" id="akfooterscript">\r\n'
+ 'if(!window.ak) var ak = function() {};\r\n'
+ 'function getIFrameDocument(iframe)\r\n'
+ '{\r\n'
+ '    var document = iframe.contentWindow || iframe.contentDocument;\r\n'
+ '    if(document.document)\r\n'
+ '        document = document.document;\r\n'
+ '    return document;\r\n'
+ '}\r\n'
+ 'ak.getIFrameDocument = function(iframe)\r\n'
+ '{\r\n'
+ '    var document = iframe.contentWindow || iframe.contentDocument;\r\n'
+ '    if(document.document)\r\n'
+ '        document = document.document;\r\n'
+ '    return document;\r\n'
+ '};\r\n'
+ '</scr' + 'ipt>\r\n'
+ '<scr' + 'ipt agkn=\'agkn\' type="text/javascript" id = "akfooterscript">\r\n'
+ '    if(!window.ak) var ak = function() {};\r\n'
+ '    if(window.onAKLoad) onAKLoad(); \r\n'
+ '    if(ak.onLoad) ak.onLoad(); \r\n'
+ '    if(ak.notifyAKDebugConsoleOfLoading) ak.notifyAKDebugConsoleOfLoading(); \r\n'
+ '</scr' + 'ipt>\r\n'
;
};

if (ak.recordRoundTripExecutionTime) ak.recordRoundTripExecutionTime();

ak.anchor = document.getElementById('akAPI');
ak.discoveryWindowContent = ak.getAKContent();
if (ak.discoveryWindowContent != null && ak.anchor != null) {
ak.anchor.innerHTML = ak.discoveryWindowContent;
setTimeout('execScripts(ak.anchor)', 2000);
}


if(!window.ak) var ak = function() {};

function getIFrameDocument(iframe)
{
    
    var document = iframe.contentWindow || iframe.contentDocument;
    
    if(document.document)
        document = document.document;
    return document;
}

ak.getIFrameDocument = function(iframe)
{
    
    var document = iframe.contentWindow || iframe.contentDocument;
    
    if(document.document)
        document = document.document;
    return document;
};
if(!window.ak) var ak = function() {};

    
    if(window.onAKLoad) onAKLoad(); 
    if(ak.onLoad) ak.onLoad(); 
    if(ak.notifyAKDebugConsoleOfLoading) ak.notifyAKDebugConsoleOfLoading();
