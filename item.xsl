<?xml version="1.0" encoding="Shift_JIS"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
   <html>
   <head>
   <title>The C Programming Language, Second Edition</title>
   <link rel="stylesheet" type="text/css" href="item.css" />
   </head>

   <body>
   <p class="title" align="left">
       The C Programming Language, Second Edition
   </p>

   <xsl:apply-templates />

   </body>
   </html>
</xsl:template>

<xsl:template match="item">

<p class="item" align="left">
  <a>
  <xsl:attribute name="href">
    <xsl:value-of select="source" />
  </xsl:attribute>
  <xsl:value-of select="abstract" />
  </a>
</p>

</xsl:template>

</xsl:stylesheet>
