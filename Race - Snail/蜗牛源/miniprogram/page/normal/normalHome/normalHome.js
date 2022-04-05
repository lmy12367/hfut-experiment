// page/normalHome/normalHome.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    currentIndex: 0,
    "firstList": [{ src: '', title: '这是一个标题', source: '这里填上来源', time: '文章的时间' },{ src: '', title: '这是一个标题', source: '这里填上来源', time: '文章的时间' },{ src: '', title: '这是一个标题', source: '这里填上来源', time: '文章的时间' }],
    "secondList": [{ src: '', title: '这是一个标题', source: '这里填上来源', time: '文章的时间' }],
    "thirdList": [{ src: '', title: '这是一个标题', source: '这里填上来源', time: '文章的时间' }],
    NewsInfo:[],
    Articles:[],
    goods:[]
  },
  //swiper切换时会调用
  pagechange: function (e) {
    if ("touch" === e.detail.source) {
      let currentPageIndex = this.data.currentIndex
      currentPageIndex = (currentPageIndex + 1) % 3
      this.setData({
        currentIndex: currentPageIndex
      })
    }
  },
  //用户点击tab时调用
  titleClick: function (e) {
    let currentPageIndex =
      this.setData({
        //拿到当前索引并动态改变
        currentIndex: e.currentTarget.dataset.idx
      })
  },
  goShops(){
    wx.redirectTo({
      url: '../normalPunblicGoods/normalPublicGoods',
    })
  },
  goGoods(){
    wx.navigateTo({
      url: '../normalGoods/normalGoods',
    })
  },
  goMyInfo(){
    wx.redirectTo({
      url: '../normalInfo/normalInfo',
    })
  },
  getByType(){
    var that = this
    wx.request({
      url: 'http://localhost:8080/artistWork/getByType',
      data:{
        type:"手工竹编"
      },
      method:'GET',
      success:function(res){
        that.setData({
          goods: res.data.data
        })
        console.log(res.data.data)
        console.log(that.data.goods)
      }
    })
  },
  getNewsInfo:function(){
    var that = this
    wx.request({
      url: 'http://c.3g.163.com/nc/article/list/T1467284926140/0-20.html',
      method:'GET',
      success:function(res){
        that.setData({
          NewsInfo: res.data.T1467284926140
        })
        console.log(that.data.NewsInfo)
      }
    })
  },
  getArticleInfo:function(){
    var that = this
    wx.request({
      url: 'http://api.tianapi.com/txapi/wxhome/index?key=cab468bc4b4a099617fb7567a161d6ba&src=txd30ffae8',
      method:'GET',
      success:function(res){
        that.setData({
          Articles: res.data.newslist
        })
        console.log(that.data.Articles)
      }
    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.getNewsInfo(),
    this.getArticleInfo(),
    this.getByType()
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