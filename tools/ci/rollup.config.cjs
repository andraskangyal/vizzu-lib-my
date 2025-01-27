const path = require('path')

const terser = require('@rollup/plugin-terser')

module.exports = [
  {
    input: path.resolve(__dirname, '../../dist/vizzu.js'),
    output: {
      file: path.resolve(__dirname, '../../dist/vizzu.min.js'),
      format: 'es',
      name: 'bundle'
    },
    plugins: [terser()]
  }
]
