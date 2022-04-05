// miniprogram/page/disable/disableReleaseGoods/disableReleaseGoods.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    title: "",
    info: "",
    point: "",
    price: "",
    type: [{
      name: "实物",
      id: 0
    }, {
      name: "虚拟",
      id: 1
    }],
    state: [{
      name: "下架",
      id: 0
    }, {
      name: "上架",
      id: 1
    }],
    productID: 0,
    category: [
      {
        categoryID: 1,
        title:"手工竹编"
      },
      {
        categoryID: 2,
        title:"陶瓷故事"
      },
      {
        categoryID: 3,
        title:"品藤编"
      },
      {
        categoryID: 4,
        title:"手工木编"
      },
      {
        categoryID: 5,
        title:"茶道类"
      },
      {
        categoryID: 6,
        title:"居家日用类"
      }
    ],
    categoryInd: -1, //类别
    typeInd: 0, //类型
    stateInd: 1, //状态
    banner: [], //轮播图片
    bannerNew: [],
    bannerAll: [],
    detail: [], //详情图片
    detailNew: [],
    detailAll: [],
    checkUp: true, //判断从编辑页面进来是否需要上传图片
    chooseViewShowDetail: true,
    chooseViewShowBanner: true,
    params: {
      productID: 0,
      contentFile: "",
      bannerFile: "",
      check: false,
    },
    dis: false,
  },
  type(e) {
    this.setData({
      typeInd: e.detail.value
    })
  },
  /**
   * 商品状态
   */
  state(e) {
    this.setData({
      stateInd: e.detail.value
    })
  },
  /**
   * 商品类别
   */
  category(e) {
    this.setData({
      categoryInd: e.detail.value
    })
  },
  formSubmit(e) {
    let that = this
    var priceTF = /^\d+(\.\d{1,2})?$/
    if (e.detail.value.title === "") {
      wx.showToast({
        title: '请输入商品名称',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (e.detail.value.title.length > 60) {
      wx.showToast({
        title: '商品名称不得大于60字',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (e.detail.value.title.length === "") {
      wx.showToast({
        title: '请输入商品价格',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (!priceTF.test(e.detail.value.price)) {
      wx.showToast({
        title: '商品价格精确到两位',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (e.detail.value.info === "") {
      wx.showToast({
        title: '请输入商品信息',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (e.detail.value.point === "") {
      wx.showToast({
        title: '请输入商品卖点',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (that.data.categoryInd === -1) {
      wx.showToast({
        title: '请选择商品类别',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (that.data.typeInd === -1) {
      wx.showToast({
        title: '请选择商品类型',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (that.data.stateInd === -1) {
      wx.showToast({
        title: '请选择商品状态',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (that.data.banner.length === 0) {
      wx.showToast({
        title: '请选择轮播图片',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    } else if (that.data.detail.length === 0) {
      wx.showToast({
        title: '请选择详情图片',
        icon: "none",
        duration: 1000,
        mask: true,
      })
    }
  },
  /** 
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})