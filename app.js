require("dotenv").config();
const express = require("express");
const app = express();
const PORT = process.env.PORT || 7777;
const products = require("./products.json"); // Load product data from JSON
const oas = require("./openai.json");
const manifest = require('./.well-known/ai-plugin.json');

app.get("/", (req, res) => {
    res.send("This is live");
});

app.get("/openai.json", (req, res) => {
    res.json(oas);
});

app.get("/.well-known/ai-plugin.json", (req, res) => {
    res.json(manifest);
});

// Endpoint to serve product data from JSON file
app.get("/api/products", (req, res) => {
    res.json(products);
});

app.get('/api/products/brand', (req, res) => {
    const productBrand = req.query.ProductBrand;
    if (!productBrand) {
      return res.status(400).json({
        error: 'Missing product brand',
      });
    }
  
    const matchedProducts = products.filter((product) => {
      const productName = product.ProductName.toLowerCase();
      return productName.includes(productBrand.toLowerCase());
    });
  
    res.json({
      matchedProducts,
    });
  });

  app.get('/api/products/search', (req, res) => {
    const productName = req.query.ProductName;
    if (!productName) {
      return res.status(400).json({
        error: 'Missing product name',
      });
    }
  
    const matchedProduct = products.find((product) => {
      const productNameLowerCase = product.ProductName.toLowerCase();
      return productNameLowerCase === productName.toLowerCase();
    });
  
    if (!matchedProduct) {
      return res.status(404).json({
        error: 'Product not found',
      });
    }
  
    res.json({
      product: matchedProduct,
    });
  });

const start = async () => {
    try {
        // No need for the database connection in this case
        app.listen(PORT, () => {
            console.log(`${PORT} Connected`);
        });
    } catch (error) {
        console.log(error);
    }
};

start();
