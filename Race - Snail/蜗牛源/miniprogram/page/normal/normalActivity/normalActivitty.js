// miniprogram/page/normal/normalActivity/normalActivitty.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    location:{
      select: false,
      location: '地区/活动',
      places: ['地区1', '地区2', '地区3'],
      select_me: "location"
    },
    person: {
      select: false,
      person: '蜗牛大V',
      people: ['王蜗牛','馨蜗牛','悦蜗牛'],
      select_me: "person"
    },
    sort: {
      select: false,
      sort: '排序',
      types: ['正序','逆序','恢复默认'],
      select_me: "sort"
    },
    activities: [
      {
        img: "",
        name: "王蜗牛",
        authentication: "流浪计划发起人",
        introduction: "致力于帮助每一只",
        local: "北京xxx地流浪猫基地"
      },
    ]
  },
  bindShowMsg_local() {
    let local = 'location.select'
    let person = 'person.select'
    let sort = 'sort.select'
    this.setData({
      [local]: !this.data.location.select,
      [person]: false,
      [sort]: false
    })
  },
  bindShowMsg_person() {
    let local = 'location.select'
    let person = 'person.select'
    let sort = 'sort.select'
    this.setData({
      [local]: false,
      [person]: !this.data.person.select,
      [sort]: false
    })
  },
  bindShowMsg_sort() {
    let local = 'location.select'
    let person = 'person.select'
    let sort = 'sort.select'
    this.setData({
      [local]: false,
      [person]: false,
      [sort]: !this.data.sort.select
    })
  },
  mySelect(e) {
    var name = e.currentTarget.dataset.name
    var which = e.currentTarget.dataset.which
    var change = which + '.' + which
    which = which + '.select'
    console.log(name)
    console.log(which)
    console.log(change)
    this.setData({
      [change]: name,
      [which]: false
    })
  },
  goDetail:function(e){
    console.log(e)
    var id = e.currentTarget.dataset.id
    wx.navigateTo({
      url: '../normalAcitivtyDetails/normalActivityDetails?id=' + id,
    })
  },
  getVolunteerInfo:function(){
    var that = this
    wx.request({
      url: 'http://localhost:8080/volunteerActivity/',
      method:'GET',
      success:function(res){
        that.setData({
          activities: res.data.data
        })
        console.log(res.data.data)
        console.log(that.data.activities)
      }
    })
  },
  
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.getVolunteerInfo()
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