<?xml version="1.0"?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:w="https://www.w3schools.com">

<xsl:template match="/">
    <html>
    <head>
      <link rel="stylesheet" type="text/css" href="item.css" />
    </head>
    <body>
        <table>
            <tr>
                <th>Name</th>
                <th>Price</th>
                <th>Calories</th>
            </tr>
            <xsl:for-each select="w:Item_catalog/w:Food_Item">
                <tr>
                    <td><xsl:value-of select="w:Name"/></td>
                    <td><xsl:value-of select="w:Price"/></td>
                    <td><xsl:value-of select="w:Calories"/></td>
                </tr>
            </xsl:for-each>
        </table>
    </body>
    </html>
</xsl:template>

</xsl:stylesheet>
