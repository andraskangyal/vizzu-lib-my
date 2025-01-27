import VizzuModule from './../cvizzu.js'
import { Module } from './module.js'

class Loader {
  constructor() {
    this._options = {}
    this._loading = null
  }

  set options(options) {
    this._options = { ...this._options, ...options }
  }

  get options() {
    return this._options
  }

  initialize() {
    if (!this._loading) this._loading = this._loadModule()
    return this._loading
  }

  async _loadModule() {
    return new Module(await VizzuModule(this._getModuleOptions()))
  }

  _getModuleOptions() {
    const moduleOptions = {}
    if (this._options?.wasmUrl) {
      moduleOptions.locateFile = (path) => {
        return path.endsWith('.wasm') ? this._options.wasmUrl : path
      }
    }
    return moduleOptions
  }
}

export const loader = new Loader()
